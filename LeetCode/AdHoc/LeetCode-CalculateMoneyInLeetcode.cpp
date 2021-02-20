struct Solution {
    int f(int b, int x) {
        if (!x) return 0;
        return f(b, x-1) + x * b;
    }
    
    int totalMoney(int n) {
        int p = n % 7 ? n / 7 : n / 7 - 1;
        
        return ((((7 + p) * (8 + p) >> 1) - (p * (p+1) >> 1)) *  (p + 1)) - (f(7, p)) - (n % 7 ? ((7 + p) * (8 + p) >> 1) - (((n % 7) + p) * ((n % 7) + p + 1) >> 1):0);
    }
};
