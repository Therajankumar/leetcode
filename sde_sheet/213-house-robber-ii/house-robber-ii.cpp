class Solution {
public:
    int rob1(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0;
        if (n == 1)
            return nums[0];

        // prev2 = max robbed up to house i-2
        // prev1 = max robbed up to house i-1
        int prev2 = 0;
        int prev1 = 0;

        for (int x : nums) {
            int take = prev2 + x; // rob current house
            int skip = prev1;     // skip current house
            int cur = max(take, skip);
            prev2 = prev1; // shift window
            prev1 = cur;
        }
        return prev1;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0;
        if (n == 1)
            return nums[0];

        vector<int> temp1, temp2;
        for (int i = 0; i < n; i++) {
            if (i != 0)
                temp1.push_back(nums[i]);
            if (i != n - 1)
                temp2.push_back(nums[i]);
        }
        return max(rob1(temp1), rob1(temp2));
    }
};