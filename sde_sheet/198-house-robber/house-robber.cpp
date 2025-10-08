class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        // prev2 = max robbed up to house i-2
        // prev1 = max robbed up to house i-1
        int prev2 = 0;
        int prev1 = 0;

        for (int x : nums) {
            int take = prev2 + x;   // rob current house
            int skip = prev1;       // skip current house
            int cur = max(take, skip);
            prev2 = prev1;          // shift window
            prev1 = cur;
        }
        return prev1; 
    }
};