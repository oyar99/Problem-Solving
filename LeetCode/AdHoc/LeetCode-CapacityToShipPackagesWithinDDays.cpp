
class Solution {
    int get_days(vector<int>& weights, int W) {
        int d = 0;
        int s = 0;
        for (int i = 0; i < weights.size(); ++i) {
            if (s + weights[i] > W) {
                ++d;
                s = 0;
            }
            s += weights[i];
        }
        if (s == 0) return d;
        return d + 1;
    }
public:
    int shipWithinDays(vector<int>& weights, int D) {
        /*  
            The minimum weight W is within the range [L, R]
            L corresponds to the heaviest item. Note that if L was smaller, then we would not be able to send that item. 
            R corresponds to the sum of weights. Note that if R was greater, then W would not be the minimum weight.
            
            The problem reduces to finding W such that we can get D subarrays each with sum less or equal than W.
            We can find W by binary search. 
            This leads to an algorithm with time complexity O(nlgn)
            
        */
        
        //Find L
        int l = 0;
        for (int i = 0; i < weights.size(); ++i) l = max(l, weights[i]);
        //Find R
        int r = 0;
        for (int i = 0; i < weights.size(); ++i) r += weights[i];
        
        //Find W
        int W;
        while (l < r) {
            int mid = (l + r) >> 1;
            int d = get_days(weights, mid);
            if (d <= D) {
                r = mid;
            } else {
                l = mid + 1;
            }
            W = l;
        }
        return W;
    }
};
