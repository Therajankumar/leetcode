class Solution {
public:
    void helper(string& tiles, vector<int>& used, string& curr, unordered_set<string>& ans) {
        for (int i = 0; i < tiles.size(); i++) {
            if (used[i]) continue;
            used[i] = 1;
            curr.push_back(tiles[i]);
            ans.insert(curr);
            helper(tiles, used, curr, ans);
            curr.pop_back();
            used[i] = 0;
        }
    }
    int numTilePossibilities(string tiles) {
       vector<int> used(tiles.size(), 0);
        string curr="";
        unordered_set<string>ans;
        helper(tiles,used ,curr,ans);
        return ans.size() ;
    }
};