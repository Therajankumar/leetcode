class Solution {
public:
   
    int minimumTotal(vector<vector<int>>& triangle) {
        int n =triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        for (int j = 0; j < n; j++) {
        dp[n - 1][j] = triangle[n - 1][j];
    }
        for (int i = n - 2; i >= 0; i--) {
        for (int j = i; j >= 0; j--) {
            // Calculate the minimum path sum for the current cell
            int down = triangle[i][j] + dp[i + 1][j];
            int diagonal = triangle[i][j] + dp[i + 1][j + 1];

            // Store the minimum of the two possible paths in dp
            dp[i][j] = min(down, diagonal);
        }
    }

    // The top-left cell of dp now contains the minimum path sum
    return dp[0][0];
        
    }
};