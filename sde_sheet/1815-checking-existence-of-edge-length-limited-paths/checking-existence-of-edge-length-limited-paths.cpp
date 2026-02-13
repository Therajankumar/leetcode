class DSU {
public:
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);

        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    bool unite(int x, int y) {
        int px = find(x);
        int py = find(y);

        if (px == py)
            return false;

        if (size[px] < size[py])
            swap(px, py);

        parent[py] = px;
        size[px] += size[py];

        return true;
    }
};
class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList,
                                           vector<vector<int>>& queries) {
        // sort kro edges by weight
        sort(edgeList.begin(), edgeList.end(),
             [](auto& a, auto& b) { return a[2] < b[2]; });

        int q = queries.size();
        // queries ko index de do

        vector<vector<int>> q2(q);
        for (int i = 0; i < q; i++) {
            q2[i] = {queries[i][0], queries[i][1], queries[i][2], i};
        }
        // sort queries by limit
        sort(q2.begin(), q2.end(),
             [](auto& a, auto& b) { return a[2] < b[2]; });
        DSU dsu(n);
        vector<bool> ans(q);

        int j = 0;

        for (int i = 0; i < q; i++) {

            int u = q2[i][0];
            int v = q2[i][1];
            int limit = q2[i][2];
            int idx = q2[i][3];

            // edge add kro limit tk
            while (j < edgeList.size() && edgeList[j][2] < limit) {
                dsu.unite(edgeList[j][0], edgeList[j][1]);
                j++;
            }

            // connectivity check kro
            ans[idx] = (dsu.find(u) == dsu.find(v));
        }

        return ans;
    }
};