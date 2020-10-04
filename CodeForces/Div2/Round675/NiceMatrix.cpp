#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
 
ll M [100][100];
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int T; cin >> T;
 
    for (int t = 0; t < T; ++t) {
        int n, m; cin >> n >> m;
 
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                cin >> M[i][j];
            
        
        ll moves = 0;
 
        for (int i = 0, ik = n - 1; i <= ik; ++i, --ik) {
            for (int j = 0, jk = m - 1; j <= jk; ++j, --jk) {
 
                vector<ll> v;
                v.push_back(M[i][j]);
                if (j!=jk) v.push_back(M[i][jk]);
                if (i!=ik) v.push_back(M[ik][j]);
                if (i!=ik && j!=jk) v.push_back(M[ik][jk]);
 
                sort(v.begin(), v.end(), greater<ll>());
 
                for (int s = 0; s < v.size() - 1; ++s) {
                    moves += abs(v[s] - v[s+1]);
                    
                    if (s != 0) v[s+1] = v[s];
                }
                
            }
        }
        
        cout << moves << endl;
    }
}
