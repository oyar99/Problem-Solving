class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int l = 0;
        int r = 0;
        
        for (int i = 0; i < k; ++i) {
            l += cardPoints[i];
        }
        
        for (int i = cardPoints.size() - 1; cardPoints.size() - 1 - i < k; --i) {
            r += cardPoints[i];
        }
        
        int ans = 0;
        int i = 0;
        int j = cardPoints.size() - 1;
        
        while (k > 0) {
            if (l >= r) {
                ans += cardPoints[i];
                l -= cardPoints[i];
                r -= cardPoints[j - k + 1];
                i++;
            } else {
                ans += cardPoints[j];
                r -= cardPoints[j];
                l -= cardPoints[i + k - 1];
                --j;
            }
            --k;
        }
        
        return ans;
    }
};
