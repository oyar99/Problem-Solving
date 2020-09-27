#pragma GCC optimize("03")

#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;

    vector<int> v(N);

    for (int i = 0; i < N; ++i) cin >> v[i];

    sort(v.begin(), v.end(), greater<int>());

    vector<int> ans(N);

    ans[0] = v[0];

    for (int i = 1; i < N - 1; ++i) ans[i] = i & 1 ? v[i+1]:v[i-1];

    if (!(N & 1)) ans[N-1] = v[N-1];
    else if (N > 1) ans[N-1] = v[N-2];

    int m = (N - 2) & 1 ? ((N - 2) >> 1) + 1: ((N - 2) >> 1);

    cout << m << endl;
    
    for (int i = 0; i < N; ++i) cout << ans[i] << " ";
    cout << endl;
}
