#include <bits/stdc++.h>

using namespace std;

int main() {
    int T, t = 1;
    cin >> T;
    while (T > 0) {
        int N, P;
        cin >> N >> P;
        vector<int> students(N);
        for (int i = 0; i < N;++i) {
            int s; cin >> s;
            students[i] = s;
        }
        sort(students.begin(), students.end());

        int l = 0;
        for (int i = 0; i < P; ++i) l += students[P-1] - students[i];

        int m = l;
        int s = l;
        for (int i = 1; i < students.size() - P + 1; ++i) {
            s = s + (students[i+P-1] - students[i+P-2]) * (P-1) - (students[i+P-2] - students[i-1]);
            m = min(m, s);
        }
        --T;
        cout << "Case #" << t++ << ": " << m << endl;
    }
}