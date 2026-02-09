class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> indegree(n, 0);
        
        // Calculate indegree
        for(auto &e : edges){
            indegree[e[1]]++;
        }
        
        // Collect nodes with indegree 0
        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(indegree[i] == 0){
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};