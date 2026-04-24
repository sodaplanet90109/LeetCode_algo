// 79 Prune and Search

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dfs(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

private:
    bool dfs(vector<vector<char>>& board, string& word, int i, int j, int idx) {
        // 找完，全部字母都配對成功
        if (idx == word.size()) return true;

        // 越界 or 字母不對
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[idx]) {
            return false;
        }

        char temp = board[i][j];                                    // 先記住原本的      
        borad[i][j] = '#';                                          // 標記已走過

        bool found = dfs(board, word, i + 1, j, idx + 1) ||         // 下   ||短路的意思
                     dfs(board, word, i - 1, j, idx + 1) ||         // 上
                     dfs(board, word, i, j + 1, idx + 1) ||         // 右
                     dfs(board, word, i, j - 1, idx + 1);           // 左

        board[i][j] = temp;                                         // 回溯Backtracking，恢復原字母
        return found;
    }
};