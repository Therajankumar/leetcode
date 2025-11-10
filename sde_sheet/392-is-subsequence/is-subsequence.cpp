class Solution {
public:
    bool helper(int i, int j, string &s, string &t, vector<vector<int>> &dp) {
        // base cases
        if (i == s.size()) return true;     
        if (j == t.size()) return false;    // t ended before s matched
        
        if (dp[i][j] != -1) return dp[i][j];

        if (s[i] == t[j])
            return dp[i][j] = helper(i + 1, j + 1, s, t, dp);
        else
            return dp[i][j] = helper(i, j + 1, s, t, dp);
    }

    bool isSubsequence(string s, string t) {
        vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, -1));
        return helper(0, 0, s, t, dp);
    }
};
