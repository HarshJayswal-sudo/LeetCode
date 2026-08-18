class Solution {
public:
    bool helper(vector<vector<char>>& board, string word, int r, int c, int w,
                vector<vector<bool>>& checked) {
        if (r < 0 || c < 0 || r >= board.size() || c >= board[0].size()) return false;
        if (checked[r][c]) return false;
        if (board[r][c] != word[w]) return false;
        if (w == word.size() - 1) return true;
        checked[r][c] = true;
        if (helper(board, word, r - 1, c, w + 1, checked)) {
            return true;
        }
        if (helper(board, word, r + 1, c, w + 1, checked)) {
            return true;
        }
        if (helper(board, word, r, c - 1, w + 1, checked)) {
            return true;
        }
        if (helper(board, word, r, c + 1, w + 1, checked)) {
            return true;
        }
        checked[r][c] = false;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> checked(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    bool ans = helper(board, word, i, j, 0, checked);
                    if (ans) return true;
                }
            }
        }
        return false;
    }
};