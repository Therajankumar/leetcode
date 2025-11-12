class Solution {
public:
    bool subsetsum(int ind, int target, vector<int>& nums, vector<vector<int>>& dp) {
        if (target == 0) return true;
        if (ind == nums.size()) return false;

        if (dp[ind][target] != -1) return dp[ind][target];

        bool pick = false;
        if (nums[ind] <= target)
            pick = subsetsum(ind + 1, target - nums[ind], nums, dp);

        bool notpick = subsetsum(ind + 1, target, nums, dp);

        return dp[ind][target] = (pick || notpick);
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (int x : nums) sum += x;

        if (sum % 2 != 0) return false;

        int target = sum / 2;
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));

        return subsetsum(0, target, nums, dp);
    }
};
