// class Solution {
// public:
//     int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
//         int n =grid.size();
//         int m =grid[0].size();
//         pair<int,int>source ={0,0};
//         pair<int,int>destination ={n-1,m-1};
//         if(grid[source.first][source.second] == 0)
//             return -1;
            
//         if(source == destination)
//             return 0;
//        vector<pair<int ,pair<int,int>>>q;
//         vector<vector<int>>dist(n,vector<int>(m,1e9));
//         q.push_back({0 ,{source.first ,source.second}});
//         int dr[] = {-1,-1,-1, 0, 0, 1, 1, 1};
//         int dc[] = {-1, 0, 1,-1, 1,-1, 0, 1};
//         while(!q.empty()){
//             auto it =q.front();
//             q.pop_back();
//             int dis =it.first;
//             int r =it.second.first;
//             int c =it.second.second;
//             for(int i =0 ;i< 8 ;i++){
//                 int newr =r+dr[i];
//                 int newc=c+dc[i];
//                 if(newr>=0 && newr<n && newc >= 0 && newc <m && dist[newr][newc] == 1 && 
//                 dis +1 <dist[newr][newc]){
//                     dist[newr][newc] =dis+1;
//                     if(newr == destination.first && newc == destination.second) return dis+1;
//                     q.push_back({dis+1 ,{newr ,newc}});
//                 }
//             }
//         }
//         return -1;
//     }
// };
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int n = grid.size();
        
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1)
            return -1;
        
        queue<pair<int,int>> q;
        q.push({0,0});
        
        grid[0][0] = 1;  // mark visited
        
        int dr[8] = {-1,-1,-1,0,0,1,1,1};
        int dc[8] = {-1,0,1,-1,1,-1,0,1};
        
        while(!q.empty()){
            auto [r,c] = q.front();
            q.pop();
            
            int dis = grid[r][c];
            
            if(r == n-1 && c == n-1)
                return dis;
            
            for(int i=0;i<8;i++){
                int newr = r + dr[i];
                int newc = c + dc[i];
                
                if(newr>=0 && newr<n &&
                   newc>=0 && newc<n &&
                   grid[newr][newc] == 0){
                    
                    grid[newr][newc] = dis + 1;
                    q.push({newr,newc});
                }
            }
        }
        
        return -1;
    }
};