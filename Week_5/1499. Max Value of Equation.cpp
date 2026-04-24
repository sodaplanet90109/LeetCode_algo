// 1499 Sliding Window + Monotonic Queue

class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        deque<pair<int, int>> dq; // {x, y-x}
        int ans = INT_MIN;

        for (auto &p : points) {
            int x = p[0], y = p[1];

            // 1. 移除超出k範圍的點
            while (!dq.empty() && x - dq.front().first > k) {
                dq.pop_front();
            }

            // 2. 用目前點更新答案
            if (!dq.empty()) {
                ans = max(ans, x + y + dq.front().second);
            }

            // 3. 維持 y-x 遞減
            int val = y - x;
            while (!dq.empty() && dq.back().second <= val) {
                dq.pop_back();
            }

            // 4. 放入目前點
            dq.push_back({x, val});
        }

        return ans;
    }
};
