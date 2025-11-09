class Solution {
public:
   void helper(vector<int>&nums ,int ind ,vector<int>&ds ,vector<vector<int>>&ans){
    if(ind == nums.size()){
        ans.push_back(ds);
        return ;
    }
    //exclude
    helper(nums,ind+1 ,ds,ans);
    //include
    int element=nums[ind];
    ds.push_back(element);
    helper(nums,ind+1,ds,ans);
    ds.pop_back();
   }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>ds;
        vector<vector<int>>ans;
        int ind=0;
        helper(nums ,ind,ds,ans);
        return ans ;
    }
};