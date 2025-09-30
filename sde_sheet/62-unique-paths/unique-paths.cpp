class Solution {
public:
    int dp[102][102];
    int countpaths(int i, int j, int m, int n) {
        if ((i == n - 1) && (j == m - 1))
            return 1;
        else if (i >= n || j >= m)
            return 0;
        else if (dp[i][j] != -1)
            return dp[i][j];
        else
            return dp[i][j] =
                       countpaths(i + 1, j, m, n) + countpaths(i, j + 1, m, n);
    }
    int uniquePaths(int m, int n) {
        memset(dp, -1, sizeof(dp));
        return countpaths(0, 0, m, n);
    }
};