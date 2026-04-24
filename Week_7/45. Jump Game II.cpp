// 45 Greedy
class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0;
        int currentEnd = 0;                             
        int farthest = 0;

        for (int i = 0; i < nums.size() - 1; i++) {
            farthest = max(farthest, i + nums[i]);      // 當前站在 i 位置時,最遠可以跳到 i + nums[i]
                                                        // 在這一跳的範圍內，找下一跳最強的位置
            if (i == currentEnd) {
                jumps++;
                currentEnd = farthest;                  // 目前這一跳最遠能走到哪
            }
        }

        return jumps;
    }
};gi