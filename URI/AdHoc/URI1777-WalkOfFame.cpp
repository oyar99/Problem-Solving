#include <bits/stdc++.h>

using namespace std;


struct cam {
    int l;
    int r;
};

bool query(vector<cam>& cameras, int p) {
    int l = 0;
    int r = cameras.size() - 1;


    while (l <= r) {
        int mid = (l + r) >> 1;

        cam c = cameras[mid];

        if (c.l <= p && c.r >= p) return true;

        if (p >= c.r) l = mid + 1;
        else r = mid - 1;
    }
    return false;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;

    for (int t = 1; t <= T; ++t) {
        int n, c; cin >> n >> c;

        vector<cam> cameras(c);

        for (int i = 0; i < c; ++i) {
            int l, r;
            cin >> l >> r;
            cameras[i] = {l, r};
        }

        sort(cameras.begin(), cameras.end(), [](const cam& a, const cam& b) {
            if (a.l == b.l) return a.r < b.r;
            return a.l < b.l;
        });

        stack<cam> st;

        st.push(cameras.front());

        for (int i = 1; i < c; ++i) {
            cam& top = st.top();

            if (top.r < cameras[i].l) st.push(cameras[i]);
            else if (top.r < cameras[i].r) top.r = cameras[i].r; 
        }

        cameras.clear();

        while (!st.empty()) {
            cam cc = st.top();
            st.pop();
            cameras.push_back(cc);
        }

        reverse(cameras.begin(), cameras.end());

        int e; cin >> e;

        int count = 0;
        for (int i = 0; i < e; ++i) {
            int s; cin >> s;
            if (query(cameras,s)) ++count;
        }

        cout << "Caso #" << t << ": " << count << endl;
    }
}
