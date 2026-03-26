
class Solution:
    def reverseKGroup(self, head, k) -> Optional[ListNode]:
        
        cur = head
        for _ in range(k):      # head 往後走k步 
            if not cur:          
                return head     # 如果不滿k，原樣回傳
            cur = cur.next      

        new_head = self.reverse(head, cur)

        head.next = self.reverseKGroup(cur, k) # 下個k

        return new_head
    
    def reverse(self, head, tail):  # head = 1; tail = 5
        prev = tail
        while head != tail:
            nxt = head.next         # 先記錄下一輪位子
            head.next =prev         # 1 -> 4 -> 5 // 2 -> 1 -> 4 -> 5 ...
            prev = head             
            head = nxt
        return prev

