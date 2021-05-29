class Solution {
    bool can_place(int x, int y, vector<vector<int>>& board) {
        
        int n = board.size();
        
        pair<int, int> moves[8] = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}, {1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        
        for (const auto& m: moves) {
            int i = x;
            int j = y;
            
            while (i >= 0 && i < n && j >= 0 && j < n) {
                if (board[i][j]) return false;
                i += m.first;
                j += m.second; 
            }
        }
        
        return true;
    }
    
    int count(vector<vector<int>>& board, int k) {
        
        int n = board.size();
        
        int c = 0;
        
        if (k == n) return 1;
        
        for (int i = 0; i < n; ++i) {
            if (can_place(i, k, board)) {
                board[i][k] = 1;
                c += count(board, k + 1);
                board[i][k] = 0;
            }
        }
        
        return c;
    }
public:
    int totalNQueens(int n) {
        vector<vector<int>> board(n, vector<int>(n));
        
        return count(board, 0);
    }
};
