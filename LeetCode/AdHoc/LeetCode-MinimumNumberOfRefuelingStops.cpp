class Solution {
    
    int canReach(vector<vector<int>>& stations) {
        int fuel = stations[0][1];
        int count = 0;
        
        priority_queue<int> pq;

        for (int i = 1; i < stations.size(); ++i) {
            int dist = stations[i][0] - stations[i-1][0];
            
            if (dist <= fuel) {
                fuel -= dist;
                pq.push(stations[i][1]);
                continue;
            }
            
            while (!pq.empty() && fuel < dist) {
                fuel += pq.top();
                ++count;
                pq.pop();
            }
        
            
            if (fuel < dist) {
                return -1;
            }
            
            fuel -= dist;
            
            pq.push(stations[i][1]);
        }
        
        return count;
        
    }
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        
        stations.insert(stations.begin(), {0, startFuel});
        stations.push_back({target, 0});
        
        return canReach(stations);
    }
};
