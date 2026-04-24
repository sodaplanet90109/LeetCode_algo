from typing import List

class Node:                                              # 存一段區間的4個狀態
    def __init__(self, s00=0, s01=0, s10=0, s11=0):
        self.s00 = s00                                   # 左端不能選，右端不能選時，這段的最大和
        self.s01 = s01
        self.s10 = s10
        self.s11 = s11                                   # 左端可以選，右端可以選時，最大和


class SegmentTree:
    def __init__(self, nums: List[int]):
        self.n = len(nums)                                                  # 陣列長度
        self.tree = [Node() for _ in range(self.n * 4)]                     # 線段樹陣列：通常開 4n 就夠裝所有節點。
        self.build(1, 0, self.n - 1, nums)

    def merge(self, L: Node, R: Node) -> Node:                              # 再區分LR，避免 X1 1X
        res = Node()
        res.s00 = max(L.s00 + R.s10, L.s01 + R.s00)
        res.s01 = max(L.s00 + R.s11, L.s01 + R.s01)
        res.s10 = max(L.s10 + R.s10, L.s11 + R.s00)
        res.s11 = max(L.s10 + R.s11, L.s11 + R.s01)
        return res

    def build(self, idx: int, l: int, r: int, nums: List[int]):
        if l == r:
            x = nums[l]
            self.tree[idx] = Node(0, 0, 0, max(0, x))
            return

        mid = (l + r) // 2
        self.build(idx * 2, l, mid, nums)                                   # idx * 2 左小孩
        self.build(idx * 2 + 1, mid + 1, r, nums)                           # idx * 2 + 1 右小孩
        self.tree[idx] = self.merge(self.tree[idx * 2], self.tree[idx * 2 + 1])

    def update(self, idx: int, l: int, r: int, pos: int, val: int):         # (idx, l, r, pos, val)
        if l == r:                                                          #找到目標位置 pos
            self.tree[idx] = Node(0, 0, 0, max(0, val))
            return

        mid = (l + r) // 2
        if pos <= mid:
            self.update(idx * 2, l, mid, pos, val)
        else:
            self.update(idx * 2 + 1, mid + 1, r, pos, val)

        self.tree[idx] = self.merge(self.tree[idx * 2], self.tree[idx * 2 + 1])


class Solution:
    def maximumSumSubsequence(self, nums: List[int], queries: List[List[int]]) -> int:
        MOD = 10**9 + 7
        seg = SegmentTree(nums)

        ans = 0
        for pos, x in queries:
            seg.update(1, 0, seg.n - 1, pos, x)
            ans = (ans + seg.tree[1].s11) % MOD

        return ans