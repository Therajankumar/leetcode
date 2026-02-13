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
        return parent[x] = find(parent[x]);  // path compression
    }

    bool unite(int x, int y) {
        int px = find(x);
        int py = find(y);

        if (px == py)
            return false;  // already connected → cycle

        if (size[px] < size[py])
            swap(px, py);

        parent[py] = px;
        size[px] += size[py];

        return true;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        int n = edges.size();
        DSU dsu(n);

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];

            if (!dsu.unite(u, v))
                return e;   
        }

        return {};
    }
};