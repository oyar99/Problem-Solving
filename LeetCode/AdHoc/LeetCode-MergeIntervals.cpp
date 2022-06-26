class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]) {
                return a[1] < b[1];
            }
            return a[0] < b[0];
        });
        
        int furthestPoint = 0;
        for (int i = 0; i < intervals.size(); ++i) {
            int start = intervals[i][0];
            int end = intervals[i][1];
            
            if (start < furthestPoint) {
                start = intervals[i][0] = furthestPoint;
            }
            
            if (start > end) {
                end = intervals[i][1] = furthestPoint;
            }
            
            furthestPoint = end;
        }
        
        vector<vector<int>> mergedIntervals;
        int l = intervals[0][0];
        
        for (int i = 0; i < intervals.size(); ++i) {
            if (!(i + 1 < intervals.size() && intervals[i][1] == intervals[i+1][0])) {
                vector<int> v = { l, intervals[i][1] };
                mergedIntervals.push_back(v);
                
                if (i + 1 < intervals.size()) {
                    l = intervals[i+1][0];   
                }
            }
        }
        
        return mergedIntervals;
    }
};
