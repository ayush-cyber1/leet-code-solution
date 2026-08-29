class Solution {
public:
    bool dfs(vector<vector<char>>& board, string& word, int i, int j, int index) {
        
        // Out of bounds
        if (i < 0 || i >= board.size() ||
            j < 0 || j >= board[0].size()) {
            return false;
        }

        // Character doesn't match
        if (board[i][j] != word[index]) {
            return false;
        }

        // Entire word found
        if (index == word.length() - 1) {
            return true;
        }

        // Mark current cell as visited
        char temp = board[i][j];
        board[i][j] = '#';

        // Search in 4 directions
        bool found =
            dfs(board, word, i + 1, j, index + 1) ||
            dfs(board, word, i - 1, j, index + 1) ||
            dfs(board, word, i, j + 1, index + 1) ||
            dfs(board, word, i, j - 1, index + 1);

        // Backtrack: restore the cell
        board[i][j] = temp;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {

                if (dfs(board, word, i, j, 0)) {
                    return true;
                }
            }
        }

        return false;
    }
};