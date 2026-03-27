import heapq
from typing import List

class Solution:
    def minimumPairRemoval(self, nums: List[int]) -> int:
        n = len(nums)
        if n <= 1:
            return 0

        left = [-1] * n
        right = [-1] * n
        alive = [True] * n

        for i in range(n):
            left[i] = i - 1
            right[i] = i + 1 if i + 1 < n else -1

        violations = 0
        for i in range(n - 1):
            if nums[i] > nums[i + 1]:
                violations += 1

        if violations == 0:
            return 0

        heap = []
        for i in range(n - 1):
            heapq.heappush(heap, (nums[i] + nums[i + 1], i))

        def bad(a: int, b: int) -> int:
            if a == -1 or b == -1:
                return 0
            return 1 if nums[a] > nums[b] else 0

        def valid(i: int, pair_sum: int) -> bool:
            j = right[i]
            return (
                i != -1 and
                j != -1 and
                alive[i] and
                alive[j] and
                left[j] == i and
                nums[i] + nums[j] == pair_sum
            )

        ans = 0

        while violations > 0:
            pair_sum, i = heapq.heappop(heap)

            if not valid(i, pair_sum):
                continue

            j = right[i]
            L = left[i]
            R = right[j]

            violations -= bad(L, i)
            violations -= bad(i, j)
            violations -= bad(j, R)

            nums[i] += nums[j]
            alive[j] = False

            right[i] = R
            if R != -1:
                left[R] = i

            violations += bad(L, i)
            violations += bad(i, R)

            if L != -1:
                heapq.heappush(heap, (nums[L] + nums[i], L))
            if R != -1:
                heapq.heappush(heap, (nums[i] + nums[R], i))

            ans += 1

        return ans