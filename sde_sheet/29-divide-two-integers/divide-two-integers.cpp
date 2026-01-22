class Solution {
public:
    int divide(int dividend, int divisor) {
         // Overflow case
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;

        // Use long long to avoid overflow
        long long a = llabs((long long)dividend);
        long long b = llabs((long long)divisor);

        long long ans = 0;

        while (a >= b) {
            long long temp = b, multiple = 1;

            // Find the biggest double of divisor <= dividend
            while ((temp << 1) <= a) {
                temp <<= 1;
                multiple <<= 1;
            }

            a -= temp;
            ans += multiple;
        }

        // Apply sign
        if ((dividend < 0) ^ (divisor < 0)) ans = -ans;

        return (int)ans;
    }
};