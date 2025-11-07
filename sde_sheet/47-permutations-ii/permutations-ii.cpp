class Solution {
public:
    void helper(vector<int>& tiles, vector<int>& used, vector<int>& curr, vector<vector<int>>& ans) {
        if (curr.size() == tiles.size()) {
            ans.push_back(curr);
            return;
        }
        for (int i = 0; i < tiles.size(); i++) {
            if (used[i]) continue;
          
            if (i > 0 && tiles[i] == tiles[i-1] && !used[i-1]) continue;

            used[i] = 1;
            curr.push_back(tiles[i]);
            helper(tiles, used, curr, ans);
            curr.pop_back();
            used[i] = 0;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());          
        vector<int> used(nums.size(), 0);        
        vector<int> curr;
        vector<vector<int>> ans;

        helper(nums, used, curr, ans);
        return ans;
    }
};
