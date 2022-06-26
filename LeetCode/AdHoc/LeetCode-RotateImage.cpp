class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int offset = 0;
        int n = matrix.size();
        int max_offset = n & 1 ? n / 2 + 1 : n / 2;
        
        while (offset < max_offset) {
            int x = offset;
            int y = offset;
            
            while (y + offset < n - 1) {
                swap(matrix[x][y], matrix[y][n-1-offset]);
                swap(matrix[x][y], matrix[n-1-offset][n-1-y]);
                swap(matrix[x][y], matrix[n-1-y][x]);
                ++y;
            }
            
            ++offset;
        }
    }
};
