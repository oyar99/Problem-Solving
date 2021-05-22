class Solution {
    void buildBoard(int n, vector<string>& board) {
        for (int i = 0; i < n; ++i) {
            string row;
            
            for (int j = 0; j < n; ++j) {
                row += ".";
            }
            board.push_back(row);
        }
    }
    bool canPlace(int x, int y, int n, vector<string>& board) {
        if (board[x][y] != '.') return false;
        
        // check row
        for (char c : board[x]) {
            if (c == 'Q') return false;
        }
        
        // check col
        for (const string& s: board) {
            if (s[y] == 'Q') return false;
        }
        
        // check diagonals
        
        {
            int i = x;
            int j = y;

            while (i >= 0 && j < n) {

                if (board[i][j] == 'Q') return false;
                --i;
                ++j;
            } 
        }
        
        {
            int i = x;
            int j = y;

            while (i < n && j >= 0) {

                if (board[i][j] == 'Q') return false;
                ++i;
                --j;
            }
        }
        
        {
            int i = x;
            int j = y;

            while (i < n && j < n) {

                if (board[i][j] == 'Q') return false;
                ++i;
                ++j;
            }
        }
        
        {
            int i = x;
            int j = y;

            while (i >= 0 && j >= 0) {

                if (board[i][j] == 'Q') return false;
                --i;
                --j;
            }
        }
        
        return true;
    }
    
    void solve(vector<string>& board, int n, int k, vector<vector<string>>& boards) {
        
        if (k > n) return;
        
        if (k == n) {
            boards.push_back(board);
            return;
        }
        
        for (int i = 0; i < n; ++i) {
            if (canPlace(i, k, n, board)) {
                board[i][k] = 'Q';
                solve(board, n, k + 1, boards);
                board[i][k] = '.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> boards;
        
        vector<string> board;
        buildBoard(n, board);
        
        solve(board, n, 0, boards);
        
        return boards;
    }
};
