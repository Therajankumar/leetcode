class Solution {
public:
    int minPathSumUtil(int i, int j, vector<vector<int>>& grid,
                       vector<vector<int>>& dp) {
        int m = grid.size();
        int n = grid[0].size();

        // Base cases
        if (i == 0 && j == 0)
            return grid[0][0];

        if (i < 0 || j < 0)
            return INT_MAX;

        if (dp[i][j] != -1)
            return dp[i][j];

        // Recursive calls
        int up = minPathSumUtil(i - 1, j, grid, dp);
        int left = minPathSumUtil(i, j - 1, grid, dp);

        int minUp = (up == INT_MAX) ? INT_MAX : grid[i][j] + up;
        int minLeft = (left == INT_MAX) ? INT_MAX : grid[i][j] + left;

        return dp[i][j] = min(minUp, minLeft);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));
        return minPathSumUtil(m - 1, n - 1, grid, dp);
    }
};