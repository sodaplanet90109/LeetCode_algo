from typing import List

class Solution:
    def reversePairs(self, nums: List[int]) -> int:
        def merge_sort(left, right):                                    # 內部函式，回傳有幾個reverse pair
            if left >= right:                                           # 區間[left, right]只有一元素或為空即回傳0
                return 0

            mid = (left + right) // 2                                   # 切兩半
            count = merge_sort(left, mid) + merge_sort(mid + 1, right)  # 遞迴分別算出左半、右半分別有多少r.p.

            # 計算跨左右兩半的 reverse pairs
            j = mid + 1                                                 # j在右半範圍
            for i in range(left, mid + 1):                              # i在左半範圍
                while j <= right and nums[i] > 2 * nums[j]:
                    j += 1
                count += j - (mid + 1)

            # 標準 merge
            temp = []
            i, j = left, mid + 1

            while i <= mid and j <= right:                              #左右都有
                if nums[i] <= nums[j]:
                    temp.append(nums[i])
                    i += 1
                else:
                    temp.append(nums[j])
                    j += 1

            while i <= mid:                                             # 左半剩
                temp.append(nums[i])
                i += 1

            while j <= right:                                           # 右半剩
                temp.append(nums[j])
                j += 1

            nums[left:right + 1] = temp
            return count

        return merge_sort(0, len(nums) - 1)