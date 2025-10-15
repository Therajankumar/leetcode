class Solution {
public:
 int coinchangeutility(int ind ,int target ,vector<int>&coins ,vector<vector<int>>&dp){
    if(target ==0) return 0;
    if(ind==0){
        if(target %  coins[ind]==0) return target / coins[ind];
        else return 1e9;
    }
    if(dp[ind][target] !=-1) return dp[ind][target];
    //not take
    int nottake =1e9;
    nottake=0+coinchangeutility(ind-1 ,target,coins,dp);
    //take
    int take=1e9;
    if(coins[ind] <= target) {
        take=1+coinchangeutility(ind ,target-coins[ind] ,coins,dp);
    }
    return dp[ind][target] =min(take,nottake);
 }
    int coinChange(vector<int>& coins, int amount) {
        int n =coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1 ,-1));
       int ans= coinchangeutility(n-1 ,amount ,coins,dp); 
    if(ans >= 1e9) return -1;
    else return ans;
    }

};