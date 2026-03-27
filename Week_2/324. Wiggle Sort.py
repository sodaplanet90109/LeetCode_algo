# 小 大 小 大 小 。。。
from typing import List

class Solution:
    def wiggleSort(self, nums: List[int]) -> None:
        nums.sort()                                 # 原地排序 in-place sort
        n = len(nums)

        small = nums[:(n+1)//2][::-1]               # 前半；反轉
        large = nums[(n+1)//2:][::-1]               # 後半；反轉

        nums[0::2] = small                          # 偶數位
        nums[1::2] = large                          # 奇數位
                                                    # [start:end:step]
        