class Solution {
public:
    double myPow(double x, int n) {
        long long m = n;
        if (m < 0) {
            m = -m;
            x = 1 / x;
        }
        if (m == 0) return 1;
        if (m == 1) return x;

        double half = myPow(x, m / 2);
        if (m % 2 == 0)
            return half * half;
        else
            return x * half * half;
    }
};