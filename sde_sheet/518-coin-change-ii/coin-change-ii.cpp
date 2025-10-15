class Solution {
public:
 int coinchangeutility(int ind ,int target ,vector<int>&coins ,vector<vector<int>>&dp){
    if (target == 0) return 1;
    if(ind==0) return (target % coins[0] ==0);
    if(dp[ind][target] !=-1) return dp[ind][target];
    //not take
   
   long long  nottake=coinchangeutility(ind-1 ,target,coins,dp);
    //take
    int take=0;
    if(coins[ind] <= target) {
        take=coinchangeutility(ind ,target-coins[ind] ,coins,dp);
    }
    return dp[ind][target] =take + nottake;
 }
    int change(int amount, vector<int>& coins) {
         int n =coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1 ,-1));
       int ans= coinchangeutility(n-1 ,amount ,coins,dp); 
   
     return ans;
    }

    
};