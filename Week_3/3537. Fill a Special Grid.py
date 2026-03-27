class Solution:
    def specialGrid(self, n) :
        if n == 0:
            return [[0]]
        
        prev = self.specialGrid(n - 1)                  # 做出更小一層grid
        m = len(prev)                                   # grid邊長
        add = m * m                                     # 有幾個數字
        
        res = [[0] * (m * 2) for _ in range(m * 2)]     # 建立一2m x 2m的矩陣，並初始化為0
        
        for i in range(m):
            for j in range(m):
                res[i][j] = prev[i][j] + 3 * add       # 左上 3
                res[i][j + m] = prev[i][j]             # 右上 0
                res[i + m][j] = prev[i][j] + 2 * add   # 左下 2
                res[i + m][j + m] = prev[i][j] + add   # 右下 1
        
        return res
        