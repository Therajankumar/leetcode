class Solution {
public:
    int maximizeExpressionOfThree(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return INT_MIN;

        int a = *max_element(nums.begin(), nums.end());
        int countA = 0;
        for (int x : nums) if (x == a) countA++;

        int b = INT_MIN;
        if (countA >= 2) {
            b = a;
        } else {
            for (int x : nums) {
                if (x != a && x > b) b = x;
            }
        }

        int c = *min_element(nums.begin(), nums.end());
        if (b == INT_MIN) return INT_MIN;

        return a + b - c;
    }
};
