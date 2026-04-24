class Solution {
public:
    string makeLargestSpecial(string s) {
        vector<string> parts;
        int count = 0, start = 0;

        for (int i = 0; i < s.size(); i++) {    // Devide: 找出block    1 + inner + 0 
            if (s[i] == '1') count++;           // 用count找出每個最外層special substring
            else count--;

            if (count == 0) {                   // 當count = 0，則有一完整block
                string inner = s.substr(start + 1, i - start - 1);
                parts.push_back("1" + makeLargestSpecial(inner) + "0");     // Conquer1: makeLargestSpecial處理inner
                start = i + 1;                                              // Conquer2: 1 + 最佳inner + 0 包回去
            }
        }

        sort(parts.begin(), parts.end(), greater<string>());                // Combine: 排序，最大字典序

        string res = "";
        for (string &p : parts) res += p;                                   // 依序取出 parts 裡每個字串 p，加到 res 後面。
        return res;                                                         // & 表示宣告reference
    }
};