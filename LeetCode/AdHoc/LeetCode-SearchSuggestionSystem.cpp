class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        
        sort(products.begin(), products.end());
        
        int n = products.size();
        
        list<int> indices;
        
        for (int i = 0; i < n; ++i) indices.push_back(i);
        
        vector<vector<string>> ans;
        
        for (int c = 0; c < searchWord.size(); ++c) {
            
            vector<string> v;
            
            auto it = indices.begin();
            
            while (it != indices.end()) {
                
                int i = *it;
                
                const string& p = products[i];
                
                if (searchWord[c] == p[c]) {
                    if (v.size() < 3) {
                        v.push_back(p);
                    }
                    ++it;
                } else {
                    indices.erase(it++);
                }
            }
            
            ans.push_back(v);
        }
        
        return ans;
    }
};
