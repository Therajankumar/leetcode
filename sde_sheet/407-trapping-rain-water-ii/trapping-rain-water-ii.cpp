class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        /*******************************************************************/
        int m = heightMap.size(), n = heightMap[0].size();
        if (m <= 2 || n <= 2)
            return 0; // No space to trap water

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>, greater<>>
            pq;

        // Step 1: Push all boundary cells
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || j == 0 || i == m - 1 || j == n - 1) {
                    pq.push({heightMap[i][j], {i, j}});
                    visited[i][j] = true;
                }
            }
        }

        // Directions
        vector<int> dir = {1, 0, -1, 0, 1};
        int water = 0;

        // Step 2: Process heap
        while (!pq.empty()) {
            auto [h, cell] = pq.top();
            pq.pop();
            int x = cell.first, y = cell.second;

            for (int k = 0; k < 4; k++) {
                int nx = x + dir[k], ny = y + dir[k + 1];
                if (nx < 0 || ny < 0 || nx >= m || ny >= n || visited[nx][ny])
                    continue;
                visited[nx][ny] = true;

                // If neighbor lower, water is trapped
                if (heightMap[nx][ny] < h) {
                    water += h - heightMap[nx][ny];
                }

                // Push updated boundary height
                pq.push({max(heightMap[nx][ny], h), {nx, ny}});
            }
        }

        return water;
    }
};