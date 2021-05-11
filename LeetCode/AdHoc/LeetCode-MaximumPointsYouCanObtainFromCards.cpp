class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        
        vector<int> P(n+1);
        P[0] = 0;
        
        for (int i = 1; i <= n; ++i) P[i] = P[i-1] + cardPoints[i-1];
        
        int best = 0;
        
        for (int i = 0, j = n - 1; k; --k) {
            int l = P[i+k] - P[i];
            int r = P[j+1] - P[j-k+1];
            
            if (l > r) best += cardPoints[i++];
            else best += cardPoints[j--];
        }
        
        return best;
    }
};
