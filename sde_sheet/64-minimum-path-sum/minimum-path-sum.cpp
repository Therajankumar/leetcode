class Solution {
public:
    int minPathSumUtil(int i, int j, vector<vector<int>>& grid,
                       vector<vector<int>>& dp) {
        int m = grid.size();
        int n = grid[0].size();

        // Base cases
        if (i == m - 1 && j == n - 1)
            return grid[i][j];
        if (i >= m || j >= n)
            return INT_MAX;

        if (dp[i][j] != -1)
            return dp[i][j];

        // Recursive calls
        int down = minPathSumUtil(i + 1, j, grid, dp);
        int right = minPathSumUtil(i, j + 1, grid, dp);

        // Combine safely (avoid INT_MAX + something)
        int best = INT_MAX;
        if (down != INT_MAX)
            best = min(best, grid[i][j] + down);
        if (right != INT_MAX)
            best = min(best, grid[i][j] + right);

        return dp[i][j] = best;
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));
        return minPathSumUtil(0, 0, grid, dp);
    }
};