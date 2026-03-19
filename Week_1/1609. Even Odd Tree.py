from collections import deque

class Solution:
    def isEvenOddTree(self, root) -> bool:
        queue = deque([root])               # 初始放入root
        is_even_level = True

        while queue:                        # queue 裡還有節點 就繼續BFS
            prev_value = float('-inf') if is_even_level else float('inf')
            # 偶數層值漸增，最先前值為負無限；奇數層為漸減，最初始值設無線大

            for _ in range(len(queue)):       # 有len(queue)個節點
                node = queue.popleft()        # "前面"取出一節點
                value = node.val              # 取得節點數值

                if is_even_level:                             # 偶數層
                    if value % 2 == 0 or value <= prev_value: # 值為奇數且遞增
                # if is_even_level and (value %2 == 0 or value <= prev_value):
                        return False
                else:                                         # 奇數層
                    if value % 2 == 1 or value >= prev_value: # 值為偶數且遞減
                # elif not is_even_level and (value %2 == 1 or value >= prev_value)
                        return False

                prev_value = value      # 更新前一個值，給下一個節點用

                # 如果下一層的節點存在，把它加入queue
                if node.left:
                    queue.append(node.left) 
                if node.right:
                    queue.append(node.right)

            is_even_level = not is_even_level
        return True

        
