class Solution {
public:
     int climbStairsutility(int n,vector<int>&dp) {
       if(n==0 || n==1) return 1 ;
      if(dp[n] !=-1) return dp[n];
       for(int i =2 ;i <=n;i++){
        return  dp[n] = climbStairsutility(n-1,dp)+climbStairsutility(n-2,dp);
       }
       return 0;
    }
    int climbStairs(int n) {
        vector<int>dp(n+1 ,-1);
        return climbStairsutility(n,dp);
    }
};