class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        
        int n = apples.size();
        auto compare = [](pair<int, int> a, pair<int, int> b) {
            return a.first > b.first;
        };
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(compare)> p(compare);
        
        int ans = 0;
        
        for (int i = 0; i < 40000; ++i) {
            if (i < n && days[i] > 0) p.push({i + days[i] - 1, apples[i]});
            
            while (!p.empty() && p.top().first < i) p.pop();
            
            if (!p.empty()) {
                ++ans;
                pair<int, int> a = p.top();
                p.pop();
                a.second--;
                
                if (a.second > 0) {
                    p.push(a);
                }
            } else if (i >= n) break;
        }
        
        return ans;
    }
};
