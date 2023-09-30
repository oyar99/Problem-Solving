#include <bits/stdc++.h>

using namespace std;
using namespace complex_literals;

typedef complex<double> cd;

vector<cd> ifft(vector<cd>&);
vector<cd> fft(vector<cd>&, int);

vector<cd> ifft(vector<cd>& a) {
    int n = a.size();

    vector<cd> y = fft(a, -1);

    for (int i = 0; i < n; ++i) {
        y[i] /= n;
    }

    return y;
}

vector<cd> fft(vector<cd>& a, int wf = 1) {
    int n = a.size();
    
    if (n == 1) {
        return a;
    }
    
    double alpha = (2 * M_PI / n) * wf;
    cd wn = cos(alpha) + sin(alpha) * 1i;
    cd w = 1.0;
    
    vector<cd> ao(n>>1);
    vector<cd> ae(n>>1);
    
    for (int i = 0; i < n; ++i) {
        if (i & 1) {
            ao[(i-1)>>1] = a[i];
        } else {
            ae[i>>1] = a[i];
        }
    }
    
    vector<cd> yo = fft(ao, wf);
    vector<cd> ye = fft(ae, wf);
    
    vector<cd> y(n);
    
    for (int k = 0; k < n>>1; ++k) {
        y[k] = ye[k] + w * yo[k];
        y[k+(n>>1)] = ye[k] - w * yo[k];
        w *= wn;
    }
    
    return y;
}

int main() {
    int n; int k; cin >> n >> k;
    
    vector<cd> v(1<<20);
    
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        v[x] = 1.0;
    }

    vector<cd> pv = fft(v);
    
    for (int i = 0; i < k - 1; ++i) {
        v = fft(v);

        for (int i = 0; i < (1<<20); ++i) {
            v[i] *= pv[i];
        }

        v = ifft(v);
    }
    
    
    for (int i = 0; i < (1<<20); ++i) {
        if (((int)round(v[i].real())) != 0) {
            cout << i << " ";
        }
    }
    
    cout << endl;
}
