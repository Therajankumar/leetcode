class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        return accumulate(nums.end()-k ,nums.end(),0) - accumulate(nums.begin(),nums.begin()+k,0);
    }
};