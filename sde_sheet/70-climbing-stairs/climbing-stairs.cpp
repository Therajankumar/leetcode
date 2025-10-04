class Solution {
public:
    int climbStairs(int n) {
        int prev = 1;
        int prev2 = 1;
        int curr_i;
        for (int i = 2; i <= n; i++) {
             curr_i = prev + prev2;
             prev2 =prev;
             prev =curr_i;
        }
        return prev;
    }
};