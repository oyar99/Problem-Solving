class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        
        // num of buildings
        int n = heights.size();
        
        long long diffs = 0;
        
        // PQ to store largest differences as we iterate over the heights
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        // sum of 'ladders' largest differences
        long long lg = 0;
        
        // we want to see if we could possibly reach the ith building by following a greedy approach
        // we will use as many ladders as possible for the largest differences in height
        for (int i = 1; i < n; ++i) {
            
            if (heights[i] <= heights[i-1]) continue;
            
            diffs += (heights[i] - heights[i-1]);

            pq.push(heights[i] - heights[i-1]);
            lg += (heights[i] - heights[i-1]);

            if (pq.size() > ladders)
                lg -= pq.top(),
                pq.pop();
            
            if (diffs - lg > bricks) return i - 1;
            
        }
        
        return n - 1;
    }
};
