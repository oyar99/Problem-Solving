#include <bits/stdc++.h>

using namespace std;

int M [1000][1000];
int HL [1000][1000];
int HR [1000][1000];
int VU [1000][1000];
int VD [1000][1000];

int main() {
    int T; cin >> T;

    for (int t = 0; t < T; ++t) {
        int r, c; cin >> r >> c;

        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                cin >> M[i][j];
            }
        }

        int count;

        for (int i = 0; i < r; ++i) {
            count = 0;
            for (int j = 0; j < c; ++j) {
                if (M[i][j] == 1) {
                    ++count;
                } else {
                    count = 0;
                }

                HR[i][j] = count;
            }
        }

        for (int i = 0; i < r; ++i) {
            count = 0;
            for (int j = c - 1; j >= 0; --j) {
                if (M[i][j] == 1) {
                    ++count;
                } else {
                    count = 0;
                }

                HL[i][j] = count;
            }
        }

        for (int j = 0; j < c; ++j) {
            count = 0;
            for (int i = 0; i < r; ++i) {
                if (M[i][j] == 1) {
                    ++count;
                } else {
                    count = 0;
                }

                VU[i][j] = count;
            }
        }

        for (int j = 0; j < c; ++j) {
            count = 0;
            for (int i = r - 1; i >= 0; --i) {
                if (M[i][j] == 1) {
                    ++count;
                } else {
                    count = 0;
                }

                VD[i][j] = count;
            }
        }

        int ans = 0;

        for (int j = 0; j < c; ++j) {
            for (int i = 0; i < r; ++i) {

                {
                    int w = HL[i][j];
                    int h = VU[i][j];

                    int lw = w * 2 > h ? h / 2 : w;
                    int lh = lw * 2;

                    ans += max(0, lw - 1);
                }

                {
                    int h = HL[i][j];
                    int w = VU[i][j];

                    int lw = w * 2 > h ? h / 2 : w;
                    int lh = lw * 2;

                    ans += max(0, lw - 1);
                }

                {
                    int w = HR[i][j];
                    int h = VU[i][j];

                    int lw = w * 2 > h ? h / 2 : w;
                    int lh = lw * 2;

                    ans += max(0, lw - 1);

                }

                {
                    int h = HR[i][j];
                    int w = VU[i][j];

                    int lw = w * 2 > h ? h / 2 : w;
                    int lh = lw * 2;

                    ans += max(0, lw - 1);

                }

                {
                    int w = HL[i][j];
                    int h = VD[i][j];

                    int lw = w * 2 > h ? h / 2 : w;
                    int lh = lw * 2;

                    ans += max(0, lw - 1);
                }

                {
                    int h = HL[i][j];
                    int w = VD[i][j];

                    int lw = w * 2 > h ? h / 2 : w;
                    int lh = lw * 2;

                    ans += max(0, lw - 1);
                }


                {
                    int w = HR[i][j];
                    int h = VD[i][j];

                    int lw = w * 2 > h ? h / 2 : w;
                    int lh = lw * 2;

                    ans += max(0, lw - 1);
                }

                {
                    int h = HR[i][j];
                    int w = VD[i][j];

                    int lw = w * 2 > h ? h / 2 : w;
                    int lh = lw * 2;

                    ans += max(0, lw - 1);
                }
            }
        }
        cout << "Case #" << (t + 1) << ": " << ans << endl;
    }
}
