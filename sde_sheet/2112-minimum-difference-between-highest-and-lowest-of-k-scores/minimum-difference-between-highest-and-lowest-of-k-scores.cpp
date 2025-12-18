class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n =nums.size();
        if(k==0) return 0;
        if(nums.size()==1 && k==1) return 0;
        sort(nums.begin(),nums.end());
        int mini=INT_MAX;
        for(int i=0 ;i+k-1<n ;i++){
            int diff =nums[i+k-1] -nums[i];
            mini =min(mini ,diff);
        }
        return mini;
    }
};