class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<int> pos(n, -1);
        vector<bool> cols(n, false);
        vector<bool> diag1(2 * n, false);
        vector<bool> diag2(2 * n, false);

        backtrack(0, n, pos, cols, diag1, diag2, result);

        return result;
    }

private:
    void backtrack(int row, int n, vector<int>& pos, vector<bool>& cols,
                    vector<bool>& diag1, vector<bool>& diag2,
                    vector<vector<string>>& result) {
        if (row == n) {
            result.push_back(buildBoard(pos, n));
            return;
        }

        for (int col = 0; col < n; col++) {
            int d1 = row - col + n;
            int d2 = row + col;

            if (cols[col] || diag1[d1] || diag2[d2]) continue;

            pos[row] = col;
            cols[col] = diag1[d1] = diag2[d2] = true;

            backtrack(row + 1, n, pos, cols, diag1, diag2, result);

            cols[col] = diag1[d1] = diag2[d2] = false;
        }
    }

    vector<string> buildBoard(vector<int>& pos, int n) {
        vector<string> board(n, string(n, '.'));
        for (int row = 0; row < n; row++) {
            board[row][pos[row]] = 'Q';
        }
        return board;
    }
};