class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
         sort(nums.begin(), nums.end());
        int n = nums.size();
        int mod = 1e9 + 7;

        vector<int> pow2(n);
        pow2[0] = 1;

        for (int i = 1; i < n; i++) {
            pow2[i] = (pow2[i-1] * 2) % mod;
        }

        int l = 0, r = n - 1;
        long long ans = 0;

        while (l <= r) {
            if (nums[l] + nums[r] <= target) {
                ans = (ans + pow2[r - l]) % mod;
                l++;
            } else {
                r--;
            }
        }

        return ans;
    }
};