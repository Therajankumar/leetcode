class Solution {
public:
    vector<vector<string>> ans;

    bool isPalindrome(string &s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end]) return false;
            start++;
            end--;
        }
        return true;
    }

    void helper(int start, string &s, vector<string> &path) {
        if (start == s.size()) { // base case: reached end
            ans.push_back(path);
            return;
        }

        for (int i = start; i < s.size(); i++) {
            if (isPalindrome(s, start, i)) {
                path.push_back(s.substr(start, i - start + 1)); // choose
                helper(i + 1, s, path); // explore
                path.pop_back(); // unchoose (backtrack)
            }
        }
    }

    vector<vector<string>> partition(string s) {
          vector<string> path;
        helper(0, s, path);
        return ans;
    }
};