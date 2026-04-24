//Devide and Conquer
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        if (buildings.empty()) return {};
        return divide(buildings, 0, buildings.size() - 1);
    }

private:
    vector<vector<int>> divide(vector<vector<int>>& buildings, int l, int r) {
        // base case: one building
        if (l == r) {
            int left = buildings[l][0];             // 左界
            int right = buildings[l][1];            // 右界
            int h = buildings[l][2];                // 高

            return {{left, h}, {right, 0}};
        }

        int mid = l + (r - l) / 2;

        vector<vector<int>> leftSky = divide(buildings, l, mid);
        vector<vector<int>> rightSky = divide(buildings, mid + 1, r);

        return mergeSkyline(leftSky, rightSky);
    }

    vector<vector<int>> mergeSkyline(vector<vector<int>>& A, vector<vector<int>>& B) 
    {
        vector<vector<int>> res;

        int i = 0, j = 0;
        int h1 = 0, h2 = 0;

        while (i < A.size() && j < B.size()) {      // size = 2
            int x = 0;

            if (A[i][0] < B[j][0]) {                // 比x，陣列第i/j列的x
                x = A[i][0];
                h1 = A[i][1];
                i++;
            }
            else if (A[i][0] > B[j][0]) {
                x = B[j][0];
                h2 = B[j][1];
                j++;
            }
            else {
                x = A[i][0];
                h1 = A[i][1];
                h2 = B[j][1];
                i++;
                j++;
            }

            int currH = max(h1, h2);

            if (res.empty() || res.back()[1] != currH) {        // res空；最後一個高度not=目前高度
                res.push_back({x, currH});
            }
        }

        while (i < A.size()) {                                  // 收尾
            if (res.empty() || res.back()[1] != A[i][1]) {
                res.push_back(A[i]);
            }
            i++;
        }

        while (j < B.size()) {
            if (res.empty() || res.back()[1] != B[j][1]) {
                res.push_back(B[j]);
            }
            j++;
        }

        return res;
    }
};