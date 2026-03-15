class Solution {
public:
    void helper(int ind , vector<int> &curr ,vector<int>&nums ,vector<vector<int>>&ans){
        if(ind == nums.size()){
            ans.push_back(curr);
            return;
        }
        //not pick
        helper(ind+1 ,curr ,nums ,ans);
        //pick
        curr.push_back(nums[ind]);
        helper(ind+1 ,curr,nums,ans);
        curr.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>curr;
        vector<vector<int>>ans;
        helper(0 ,curr ,nums ,ans);
        return ans ;
    }
};