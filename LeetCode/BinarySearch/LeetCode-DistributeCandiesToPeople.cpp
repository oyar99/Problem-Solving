typedef long long ll;

class Solution {
public:
    vector<int> distributeCandies(int c, int n) {
        vector<int> v(n);
        vector<ll> K(n);
        int s = 0;
        
        ll l = 0;
        ll r = 1e5;

        while (l < r) {
            ll k = (l + r) >> 1;

            if ((k*n*(k*n+1)>>1)+((((k*n+1)*(k*n+2)>>1))-((k*n*(k*n+1)>>1)))<=c) l = k + 1;
            else r = k;
        }
        
        ll k = l-1;
        
        for (int i = 0; i < n; ++i) {
            if ((k*n*(k*n+1)>>1)+((((k*n+i+1)*(k*n+i+2)>>1))-((k*n*(k*n+1)>>1)))>c) --k;
        
            v[i] = (k*n*(k+1)>>1)+(k+1)*(i+1);
            K[i] = k;
            s += v[i];
        }
        
        for (int i = 1; i < n; ++i) {
            if (K[i] != K[i-1]) {
                v[i] += (c - s);
                s += (c - s);
                break;
            }
        }

        if (s != c) v[0] += (c - s);
        
        return v;
    }
};
