// 1383 Greedy
class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        const int MOD = 1e9 + 7;

        vector<pair<int, int>> engineers;
        for (int i = 0; i < n; ++i) {
            engineers.push_back({efficiency[i], speed[i]});         // 把同一位工程師組成：{efficiency, speed}
        }

        sort(engineers.rbegin(), engineers.rend());                 // 依 efficiency 由大到小排序, r是reverse

        priority_queue<int, vector<int>, greater<int>> minHeap;     // greater形成「最小堆」, 存speed
        long long speedSum = 0;
        long long ans = 0;

        for (auto& [eff, spd] : engineers) {
            minHeap.push(spd);                                      // 先加入目前工程師
            speedSum += spd;                                        // 目前速度總和
            
            if ((int)minHeap.size() > k) {
                speedSum -= minHeap.top();                          // 如果超過 k 人，先取值
                minHeap.pop();                                      // 再
            }

            ans = max(ans, speedSum * eff);                         // 目前 eff 是團隊最小 efficiency
        }

        return ans % MOD;
    }
};