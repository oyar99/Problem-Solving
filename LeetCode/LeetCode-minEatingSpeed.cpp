class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        int l = 0;
        int r = 0;
        
        for (int i = 0; i < piles.size();++i) r = max(piles[i], r);
        
        int k = 0;
        while (l < r) {
            int mid = ((unsigned)l + (unsigned)r) >> 1;
            if (mid == 0) break;
            int h = 0;
            for (int i = 0; i < piles.size();++i) h += ceil((double)piles[i] / mid);
            
            if (h <= H) r = mid, k = mid;
            else l = mid+1, k = mid+1; 
        }
        return k;
    }
};