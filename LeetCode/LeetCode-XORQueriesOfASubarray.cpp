//O(nlgn+qlgn)

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int logs[(int)3e4];
        
        logs[1] = 0;
        for (int i = 2; i <= arr.size(); ++i) logs[i] = logs[i >> 1] + 1;
        
        int st[15][(int)3e4];
        
        for (int i = 0; i <= logs[arr.size()]; ++i) {
            for (int j = 0; j + (1 << i) <= arr.size(); ++j) {
                if ((1 << i) == 1) st[i][j] = arr[j];
                else st[i][j] = st[i-1][j] ^ st[i-1][j + ((1 << i) >> 1)];
            }
        }
        
        vector<int> ans(queries.size());
        
        for (int q = 0; q < queries.size(); ++q) {
            int l = queries[q][0];
            int r = queries[q][1];
            
            int y = 0;
            while (l <= r) {
                y ^= st[logs[r-l+1]][l];
                l += (1 << logs[r-l+1]);
            }
            ans[q] = y;
        }
        return ans;
    }
};
