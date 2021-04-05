class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = speed.size();
        vector<pair<int, int>> v;
        
        for (int i = 0; i < n; ++i) {
            v.push_back({position[i], speed[i]});
        }
        
        sort(v.begin(), v.end(), [](auto a, auto b) {
           if (a.first == b.first) return a.second < b.second;
            
            return a.first < b.first;
        });
        
        vector<double> t(n);
        
        for (int i = 0; i < n; ++i) {
            t[i] = (double)(target - v[i].first) / v[i].second;
        }
        
        stack<int> s;
        int groups = 0;
        
        for (int i = n - 1; i >= 0; --i) {
            while (!s.empty() && t[i] > t[s.top()]) {
                s.pop();
            }
            
            if (i != n - 1 && s.empty()) ++groups;
            
            s.push(i);
        }
        
        if (!s.empty()) ++groups;
        
        return groups;
    }
};
