// Greedy + Sliding Window to track active flips.

class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> diff(n, 0);                // 記錄某個起始位置有無翻轉(?
        int flip = 0;                          // 目前這個位置的翻轉次數
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (i >= k) {
                flip -= diff[i - k];            // 移除已經過期的翻轉影響
            }

            // 如果目前這格實際上是 0，就必須從這裡翻
            if ((nums[i] + flip) % 2 == 0) {
                if (i + k > n) return -1;  // 不夠長，無解

                ans++;
                flip++;          // 新增一次翻轉影響
                diff[i] = 1;     // 記錄這次翻轉是從 i 開始的
            }
        }

        return ans;
    }
};