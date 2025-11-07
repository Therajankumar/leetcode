class Fenwick {
public:
    vector<long long> bit;
    int n;
    Fenwick(int n) : n(n), bit(n + 1, 0) {}
    void add(int idx, int val) {
        for (idx++; idx <= n; idx += idx & -idx)
            bit[idx] += val;
    }
    long long sum(int idx) {
        long long s = 0;
        for (idx++; idx > 0; idx -= idx & -idx)
            s += bit[idx];
        return s;
    }
};

class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> pos2(n);
        for (int i = 0; i < n; i++) pos2[nums2[i]] = i;

        vector<int> mapped(n);
        for (int i = 0; i < n; i++) mapped[i] = pos2[nums1[i]];

        Fenwick bitL(n), bitR(n);
        vector<long long> left(n), right(n);

        // Left smaller counts
        for (int i = 0; i < n; i++) {
            left[i] = bitL.sum(mapped[i] - 1);
            bitL.add(mapped[i], 1);
        }

        // Right greater counts
        for (int i = n - 1; i >= 0; i--) {
            right[i] = bitR.sum(n - 1) - bitR.sum(mapped[i]);
            bitR.add(mapped[i], 1);
        }

        long long ans = 0;
        for (int i = 0; i < n; i++)
            ans += left[i] * right[i];

        return ans;
    }
};
