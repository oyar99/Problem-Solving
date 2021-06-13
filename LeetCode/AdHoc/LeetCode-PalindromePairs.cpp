class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        
        /*
        
        Assume |w(i)| >= |w(j)|

        w(i) + w(j) is a palindrome
	        iff w(j) is equal to a suffix of w(i) and the correspoding prefix is a palindrome
 
        This also holds when |w(j)| > |w(i)|
        
        */
        
        int n = words.size();
        
        vector<vector<int>> ans;
        ans.reserve(n * (n - 1) / 2);
        
        for (int i = 0; i < n; ++i) {
            
            for (int j = 0; j < n; ++j) {
                
                if (i == j) continue;
                
                bool holds = true;
                
                for (int k = 0; k < min(words[i].size(), words[j].size()); ++k) {
                    if (words[i][k] != words[j][words[j].size() - (1 + k)]) {
                        holds = false;
                        break;
                    }
                }
                
                if (!holds) continue;
                
                if (words[i].size() >= words[j].size()) {
                    
                    for (int k = words[j].size(); k < words[i].size(); ++k) {
                        if (words[i][k] != words[i][words[i].size() + words[j].size() - (1 + k)]) {
                            holds = false;
                            break;
                        }
                    }
                    
                } else {

                    for (int k = 0; k < words[j].size() - words[i].size(); ++k) {
                        if (words[j][k] != words[j][words[j].size() - (1 + k + words[i].size())]) {
                            holds = false;
                            break;
                        }
                    }
                }
                
                if (holds) ans.push_back({i, j});
            }
        }
        
        return ans;
    }
};
