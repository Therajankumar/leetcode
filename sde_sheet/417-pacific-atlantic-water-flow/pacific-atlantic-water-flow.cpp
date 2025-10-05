class Solution {
public:
    int m, n;
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();
        
        vector<vector<int>> pacific(m, vector<int>(n, 0));
        vector<vector<int>> atlantic(m, vector<int>(n, 0));
        
        // DFS from Pacific (top and left)
        for(int i = 0; i < m; i++) dfs(heights, pacific, i, 0);
        for(int j = 0; j < n; j++) dfs(heights, pacific, 0, j);
        
        // DFS from Atlantic (bottom and right)
        for(int i = 0; i < m; i++) dfs(heights, atlantic, i, n - 1);
        for(int j = 0; j < n; j++) dfs(heights, atlantic, m - 1, j);
        
        // Collect cells reachable by both oceans
        vector<vector<int>> res;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(pacific[i][j] && atlantic[i][j]) {
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }
    
    void dfs(vector<vector<int>>& heights, vector<vector<int>>& visited, int i, int j) {
        visited[i][j] = 1;
        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        
        for(auto &dir : dirs) {
            int x = i + dir[0], y = j + dir[1];
            if(x < 0 || x >= m || y < 0 || y >= n || visited[x][y]) continue;
            if(heights[x][y] < heights[i][j]) continue;
            dfs(heights, visited, x, y);
        }
    }
};
