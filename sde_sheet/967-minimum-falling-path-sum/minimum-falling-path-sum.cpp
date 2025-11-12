class Solution {
public:
    int utility(int i, int j, vector<vector<int>>& matrix,
        vector<vector<int>>& dp) {
        int n = matrix.size();
        int m = matrix[0].size();
        // base case
       if (j < 0 || j >= m) return 1e9;
       if(i==n-1) return matrix[i][j];
       
        if (dp[i][j] != -101)
            return dp[i][j];
        int  down = matrix[i][j] + utility(i + 1, j, matrix, dp);
        int  diagonalR = matrix[i][j] + utility(i + 1, j + 1, matrix, dp);
        int diagonalL = matrix[i][j] + utility(i + 1, j - 1, matrix, dp);

        return dp[i][j] = min(down, min(diagonalL, diagonalR));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -101));
       int ans = INT_MAX;

        // start from top row, try every column
        for (int j = 0; j < m; j++)
            ans = min(ans, utility(0, j, matrix, dp));

        return ans;
    }
};