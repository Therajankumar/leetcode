class Solution {
public:
    
    bool dfs(int src, int target, vector<vector<int>>& adj, vector<int>& visited) {
        if (src == target) return true;
        
        visited[src] = 1;
        
        for (auto neighbor : adj[src]) {
            if (!visited[neighbor]) {
                if (dfs(neighbor, target, adj, visited))
                    return true;
            }
        }
        
        return false;
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        int n = edges.size();
        vector<vector<int>> adj(n + 1);
        
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            
            vector<int> visited(n + 1, 0);
            
            // If path already exists → cycle
            if (!adj[u].empty() && !adj[v].empty() && dfs(u, v, adj, visited)) {
                return edge;
            }
            
            // Add edge
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        return {};
    }
};