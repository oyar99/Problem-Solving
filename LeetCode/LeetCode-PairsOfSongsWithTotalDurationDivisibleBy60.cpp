class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> buckets(60);
        
        for (int i = 0; i < time.size(); ++i) buckets[time[i] % 60]++;
        
        int count = buckets[0] * (buckets[0] - 1) / 2;
        count += buckets[30] * (buckets[30] - 1) / 2;
        
        for (int i = 1; i < 30; ++i) count += buckets[i] * buckets[60 - i];
        
        return count;
    }
};
