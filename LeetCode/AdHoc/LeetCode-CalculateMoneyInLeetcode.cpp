struct Solution {
    // Computes the recursive function
    // f(0) = 0
    // f(x) = f(x-1) + x * b
    int f(int b, int x) {
        return x?f(b,x-1)+x*b:0;
    }
    
    int totalMoney(int n) {
        // The total amount of money that will be there at the end of the nth day can be computed by this algo:
        
        // 1. Let p be the last week (zero-based indexing) (p = n%7?n/7:n/7-1).
        // 2. let m = (Σ i (from i = p+1 to 7+p)) * (p + 1). This can be derived from the two summations: (Σ i (from i = 1 to 7+p) - Σ j (from j = 1 to p + 1)).
        // 3. Substract f(7, p) from m. (This refers to the extra amount of money that is included in step 2).
        // 4. Substract the money for the days of the last week which come after the nth day.
        return ((((7+(n%7?n/7:n/7-1))*(8+(n%7?n/7:n/7-1))>>1)-((n%7?n/7:n/7-1)*((n%7?n/7:n/7-1)+1)>>1))*((n%7?n/7:n/7-1)+1))-
            (f(7,(n%7?n/7:n/7-1)))-(n%7?((7+(n%7?n/7:n/7-1))*(8+(n%7?n/7:n/7-1))>>1)-(((n%7)+(n%7?n/7:n/7-1))*((n%7)+(n%7?n/7:n/7-1)+1)>>1):0);
    }
};
