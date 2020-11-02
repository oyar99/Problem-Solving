#pragma GCC optimize("O3")

#include <bits/stdc++.h>

#define INF 100000000

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;  cin >> T;

    for (int t = 0; t < T; ++t) {
        int a, b; cin >> a >> b;

        string s; cin >> s;

        vector<pair<int, int>> clusters;

        int l = 0;

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '1' && (i == 0 || s[i-1] == '0')) l = i;
            if (s[i] == '1' && (i == s.size() - 1 || s[i+1] == '0')) clusters.push_back({l, i});
        }

        vector<int> diff;

        for (int i = 1; i < clusters.size(); ++i) diff.push_back(clusters[i].first - clusters[i-1].second - 1);
        
        sort(diff.begin(), diff.end());

        int ans = INF;

        int c = clusters.size();

        int places = 0;

        for (int i = 0; i < diff.size(); ++i) {
            ans = min(ans, c * a + places * b);
            places += diff[i];
            --c;
        }

        ans = min(ans, c * a + places * b);

        cout << ans << endl;
    }
}