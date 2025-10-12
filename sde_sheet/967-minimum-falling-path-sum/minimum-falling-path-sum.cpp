class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));

        // base case: first row same as matrix
        for (int j = 0; j < m; j++)
            dp[0][j] = matrix[0][j];

        // fill from 2nd row to last
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int up = matrix[i][j] + dp[i - 1][j];

                int leftDiag = matrix[i][j];
                if (j - 1 >= 0)
                    leftDiag += dp[i - 1][j - 1];
                else
                    leftDiag = 1e9;

                int rightDiag = matrix[i][j];
                if (j + 1 < m)
                    rightDiag += dp[i - 1][j + 1];
                else
                    rightDiag = 1e9;

                dp[i][j] = min({up, leftDiag, rightDiag});
            }
        }

        // answer = minimum of last row
        int ans = INT_MAX;
        for (int j = 0; j < m; j++)
            ans = min(ans, dp[n - 1][j]);

        return ans;
    }
};