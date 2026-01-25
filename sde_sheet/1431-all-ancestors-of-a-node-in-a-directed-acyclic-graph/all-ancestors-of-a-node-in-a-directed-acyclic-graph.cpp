class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);

        // Step 1: build graph
        for (auto &e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            indegree[v]++;
        }

        // Step 2: ancestors storage
        vector<set<int>> ancestors(n);

        // Step 3: topo sort queue
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        // Step 4: topo processing
        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : adj[u]) {
                ancestors[v].insert(u);
                for (int x : ancestors[u]) {
                    ancestors[v].insert(x);
                }

                indegree[v]--;
                if (indegree[v] == 0)
                    q.push(v);
            }
        }

        // Step 5: convert to vector
        vector<vector<int>> ans(n);
        for (int i = 0; i < n; i++) {
            for (int x : ancestors[i])
                ans[i].push_back(x);
        }

        return ans;
    }
};