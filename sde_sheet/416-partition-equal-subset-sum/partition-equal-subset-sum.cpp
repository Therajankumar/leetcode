class Solution {
public:
bool subsetSum(vector<int> &arr, int sum, int n) {
    vector<bool> dp(sum + 1, false);

    // Base case: sum 0 is always possible
    dp[0] = true;

    for (int i = 0; i < n; i++) {
        // Traverse backwards to avoid using the same element multiple times
        for (int j = sum; j >= arr[i]; j--) {
            dp[j] = dp[j] || dp[j - arr[i]];
        }
    }

    return dp[sum];
}
    bool canPartition(vector<int>& nums) {
     int n = nums.size();
     int sum =0;
     for(int i=0 ;i <n;i++){
        sum += nums[i];
     }   
     if(sum % 2 != 0 ) return false;
     else return subsetSum(nums ,sum/2 ,n);
    }
};