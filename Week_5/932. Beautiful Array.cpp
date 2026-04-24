// Divide and Conquer + Constructive Algorithm，不是sliding window

class Solution {
public:
    vector<int> beautifulArray(int n) {
        vector<int> res = {1};                      // 初始化 res

        while (res.size() < n) {                    // 還沒到n就繼續擴張
            vector<int> temp;

            // 先放奇數
            for (int x : res) {                     // 把res每個元素應射成 2x-1
                if (2 * x - 1 <= n) {
                    temp.push_back(2 * x - 1);
                }
            }

            // 再放偶數
            for (int x : res) {
                if (2 * x <= n) {
                    temp.push_back(2 * x);
                }
            }

            res = temp;
        }

        return res;
    }
};