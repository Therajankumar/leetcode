class Solution {
public:
   bool isHappy(int n, unordered_set<int>& seen) {
        // Base case 1: if we reach 1, it's a happy number
        if (n == 1) return true;

        // Base case 2: if we see the same number again, it's a cycle
        if (seen.count(n)) return false;

        seen.insert(n);

        // solve 1 
        int sum = 0;
        int temp = n;
        while (temp > 0) {
            int digit = temp % 10;
            sum += digit * digit;
            temp /= 10;
        }

        // Recursive call 
        return isHappy(sum, seen);
    }
    bool isHappy(int n) {
         unordered_set<int> seen;
        return isHappy(n, seen);
    }
};