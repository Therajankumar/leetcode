class Solution {
public:
    int totalEmpty = 0; // count total valid cells (non -1)
    int paths = 0;      // count of valid paths

    int utility(int m, int n, int count, vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        // boundary + obstacle check
        if (m < 0 || n < 0 || m >= rows || n >= cols || grid[m][n] == -1)
            return 0;

        // reached destination
        if (grid[m][n] == 2) {
            if (count == totalEmpty) paths++;
            return 0;
        }

        int temp = grid[m][n];
        grid[m][n] = -1; // mark visited

        // explore 4 directions
        utility(m - 1, n, count + 1, grid);
        utility(m + 1, n, count + 1, grid);
        utility(m, n - 1, count + 1, grid);
        utility(m, n + 1, count + 1, grid);

        grid[m][n] = temp; // backtrack
        return 0;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int startX = 0, startY = 0;

        // count total non-obstacle cells + find start
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != -1) totalEmpty++;
                if (grid[i][j] == 1) {
                    startX = i;
                    startY = j;
                }
            }
        }

        utility(startX, startY, 1, grid);
        return paths;
    }
};
