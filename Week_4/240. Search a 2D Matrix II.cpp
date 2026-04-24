// 用雙指標從右上搜尋，沒有用Devide and Conquer

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }

        int m = matrix.size();
        int n = matrix[0].size();

        int row = 0;
        int col = n - 1;   // 從右上角開始

        while (row < m && col >= 0) {
            if (matrix[row][col] == target) {
                return true;
            }
            else if (matrix[row][col] > target) {
                col--;     // 太大，往左
            }
            else {
                row++;     // 太小，往下
            }
        }

        return false;
    }
};