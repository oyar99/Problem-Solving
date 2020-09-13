class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        vector<string> v;
        
        unordered_map<string, int> m;
        
        string word = "";
        for (int i = 0; i < A.size(); ++i) {
            if (A[i] == ' ') {
                m[word]++;
                word = "";
                continue;
            }
            word.push_back(A[i]);
        }
        
        m[word]++;
        
        word = "";
        for (int i = 0; i < B.size(); ++i) {
            if (B[i] == ' ') {
                m[word]++;
                word = "";
                continue;
            }
            word.push_back(B[i]);
        }
        
        m[word]++;
        
        for (const auto& w: m) {
            if (w.second == 1) v.push_back(w.first);
        }
        
        return v;
        
    }
};
