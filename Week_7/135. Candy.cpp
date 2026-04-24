class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candies(n, 1);                                  // 每人先給 1 顆, [1,1,1,1,...] n個

        for (int i = 1; i < n; i++) {                               // 左到右：處理比左邊高的情況
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }

        for (int i = n - 2; i >= 0; i--) {                          // 右到左：處理比右邊高的情況
            if (ratings[i] > ratings[i + 1]) {
                candies[i] = max(candies[i], candies[i + 1] + 1);
            }
        }

        int total = 0;                                              // 加總
        for (int c : candies) {
            total += c;
        }

        return total;
    }
};