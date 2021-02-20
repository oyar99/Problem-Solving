struct Solution {    
    // Calculate money in leet code bank
    // Time Complexity: O(1)
    // Space Complexity: O(1)
    int totalMoney(int n,int d=7) {
        // The total amount of money that will be there at the end of the nth day can be computed by this algo:
        
        // 1. Let p be the last week (zero-based indexing) (p = n%7?n/7:n/7-1).
        // 2. let m = (Σ i (from i = p+1 to 7+p)) * (p + 1). This can be derived from the two summations: (Σ i (from i = 1 to 7+p) - Σ j (from j = 1 to p + 1)).
        // 3. Substract (Σ i (from i = 1 to p)) * 7 from m. (This refers to the extra amount of money that is included in step 2).
        // 4. Substract the money for the days of the last week which come after the nth day.
        int p = n%d?n/d:n/d-1;
        return ((((d+p)*(d+p+1)>>1)-(p*(p+1)>>1))*(p+1))-((p*(p+1)>>1)*d)-(n%d?((d+p)*(d+p+1)>>1)-(((n%d)+p)*((n%d)+p+1)>>1):0);
    }
};
