// 710 Hash Mapping + Random Sampling

class Solution {
private:
    unordered_map<int, int> mp;
    int m;

public:
    Solution(int n, vector<int>& blacklist) {
        m = n - blacklist.size();                                           // 算可以抽的長度

        unordered_set<int> blackSet(blacklist.begin(), blacklist.end());    // 把 blacklist 放進 blackset

        int last = n - 1;                                                   // 原長度，從尾巴拿補洞的合法數字

        
        for (int b : blacklist) {                            // 只處理 < m 的黑名單數字
            if (b < m) {                                     // 對於前半段的黑名單
                // 找到後半段沒被 blacklist 擋掉的合法數字
                while (blackSet.count(last)) {      
                    last--;                                  // 如果 last 也是黑名單，就跳過
                }
                mp[b] = last;                                // 把前半段的黑名單 b 對應到後半段合法數字 last
                last--;
            }
        }
    }

    int pick() {
        int x = rand() % m;
        if (mp.count(x)) return mp[x];                       // 如果抽到的是前半段黑名單，就改成映射後的值
        return x;
    }
};