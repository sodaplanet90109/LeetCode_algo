import heapq

class Solution:
    def mergeKLists(self, lists):
        heap = []

        # 先把每條 list 的頭放進 heap
        for i, node in enumerate(lists):
            if node:                                                    # 不為空
                heapq.heappush(heap, (node.val, i, node))               # 頭節點丟進heap，用val排序

        dummy = ListNode(0)                                             # 設立dummy，避免處理第一個節點
        cur = dummy

        while heap:
            val, i, node = heapq.heappop(heap)                          # 拿出heap拿出最小節點

            cur.next = node                                             # 把最小節點接到答案後面
            cur = cur.next                                              # 指標往前移

            if node.next:                                               # heap補上剛拿出的node的list的下一個
                heapq.heappush(heap, (node.next.val, i, node.next))

        return dummy.next