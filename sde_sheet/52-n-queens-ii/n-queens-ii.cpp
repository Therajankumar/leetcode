class Solution {
public:
    int count = 0;
    vector<int> col, diag1, diag2;

    void solve(int row, int n) {
        if (row == n) {
            count++;
            return;
        }

        for (int c = 0; c < n; c++) {
            if (col[c] || diag1[row - c + n - 1] || diag2[row + c])
                continue;

            col[c] = diag1[row - c + n - 1] = diag2[row + c] = 1;
            solve(row + 1, n);
            col[c] = diag1[row - c + n - 1] = diag2[row + c] = 0;
        }
    }

    int totalNQueens(int n) {
        col.assign(n, 0);
        diag1.assign(2 * n - 1, 0);
        diag2.assign(2 * n - 1, 0);

        solve(0, n);
        return count;
    }
};
