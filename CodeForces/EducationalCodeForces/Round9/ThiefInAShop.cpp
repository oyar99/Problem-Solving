#include <bits/stdc++.h>
#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif

#pragma GCC optimize("Ofast")

using namespace std;
using namespace complex_literals;

typedef complex<double> cd;

int N = 1 << 16;

vector<cd> ifft(const vector<cd>&);
vector<cd> fft(const vector<cd>&, int);
vector<cd> mult(const vector<cd>&, const vector<cd>&);
vector<cd> exp(const vector<cd>&, int);

vector<cd> ifft(const vector<cd>& a) {
    int n = a.size();

    vector<cd> y = fft(a, -1);

    for (int i = 0; i < n; ++i) {
        y[i] /= n;
    }

    return y;
}

vector<cd> fft(const vector<cd>& a, int wf = 1) {
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

vector<cd> mult(const vector<cd>& a, const vector<cd>& b) {
    vector<cd> pva = fft(a);
    vector<cd> pvb = fft(b);

    vector<cd> pvc(N);

    for (int i = 0; i < (N); ++i) {
        pvc[i] = pva[i] * pvb[i];
    }

    return ifft(pvc);
}

vector<cd> exp(const vector<cd>& a, int k) {
    if (k == 1) {
        return a;
    }

    if (k & 1) {
        vector<cd> c = exp(a, (k-1) >> 1);
        c = mult(c, c);
        return mult(c, a);
    } else {
        vector<cd> c = exp(a, k >> 1);
        return mult(c, c);
    }
}

int main() {
    int n; int k; cin >> n >> k;
    
    vector<cd> v(N);
    
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        v[x] = 1.0;
    }

    v = exp(v, k);
    
    for (int i = 0; i < (N); ++i) {
        if (abs(round(v[i].real())) - 1e-4 >= 0) {
            cout << i << " ";
        }
    }
    
    cout << endl;
}
