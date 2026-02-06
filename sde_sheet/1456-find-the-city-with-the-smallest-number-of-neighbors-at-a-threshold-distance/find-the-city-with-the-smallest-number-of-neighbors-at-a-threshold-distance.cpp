class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto &e : edges){
            int u = e[0];
            int v = e[1];
            int w = e[2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, w}); 
        } 
        int ansCity =-1;
        int minCount =INT_MAX;
        // Run Dijkstra from every city
        for(int src = 0; src < n; src++){
         priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int>dist(n ,INT_MAX);
        dist[src] =0;
        pq.emplace(0 ,src);
        while(!pq.empty()){
            auto top =pq.top();
            pq.pop();
            int d =top.first;
            int u =top.second;
            if(d > dist[u]) continue;
            for(auto &p :adj[u]){
                int v =p.first;
                int w =p.second;
                if(dist[u] +w < dist[v]){
                    dist[v] =dist[u]+w;
                    pq.emplace(dist[v] ,v);
                }
            }
        }
        
        // Count reachable cities (excluding itself)
            int cnt = 0;
            for(int i = 0; i < n; i++){
                if(i != src && dist[i] <= distanceThreshold)
                    cnt++;
            }

            // Update answer (tie → larger index)
            if(cnt <= minCount){
                minCount = cnt;
                ansCity = src;
            }
        }

        return ansCity;
    }
};