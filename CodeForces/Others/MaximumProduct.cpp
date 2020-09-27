#include <bits/stdc++.h>
    
using namespace std;
    
typedef unsigned long long ll;
    
struct Node {
    int i;
    int j;
    int k;
    int w;
};
    
ll memo[20][2][2][2];
    
Node path[20][2][2][2];
    
//k is 1 if the number is upper tight
//j is 1 if the number is lower tight
//w is 1 if we are dealing with a number n > 0
ll solve(vector<int>& da, vector<int>& db,int i, int j, int k, int w) {
    
    if (i >= da.size() && w) return 1L;
    if (i >= da.size()) return 0L;
    
    if (memo[i][j][k][w] != -1) return memo[i][j][k][w];
    
    int l = 0;
    
    if (j) l = da[i];
    
    int r = 9;
    
    if (k) r = db[i];
    
    ll m = 0;
    
    //try each digit
    Node optm = {-1, -1, -1, -1};
    for (ll x = l; x <= r; ++x) {
        ll temp = 0;
        Node node = {-1, -1, -1, -1};
        if (j && k) {
            if (w) {
                temp = x * solve(da, db, i + 1, x == l, x == r, w);
                node = {i+1,x==l,x==r,w};
            }
            else {
                temp = (x == 0 ? 1: x) * solve(da, db, i + 1, x == l, x == r, x != 0);
                node = {i+1,x==l,x==r,x!=0};
            }
        } else if (j) {
            if (w) {
                temp = x * solve(da, db, i + 1, x == l, k, w);
                node = {i+1,x==l,k,w};
            }
            else {
                temp = (x == 0 ? 1: x) * solve(da, db, i + 1, x == l, k, x != 0);
                node = {i+1,x==l,k,x!=0};
            }
        } else if (k) {
            if (w) {
                temp = x * solve(da, db, i + 1, j, x == r, w);
                node = {i+1,j,x==r,w};
            }
            else {
                temp = (x == 0 ? 1: x) * solve(da, db, i + 1, j, x == r, x != 0);
                node = {i+1,j,x==r,x!=0};
            }
        } else {
            if (w) {
                temp = x * solve(da, db, i + 1, j, k, w);
                node = {i+1,j,k,w};
            }
            else {
                temp = (x == 0 ? 1: x) * solve(da, db, i + 1, j, k, x != 0);
                node = {i+1,j,k,x!=0};
            }
        }
        if (temp >= m) {
            m = temp;
            optm = node;
        }
    }
    memo[i][j][k][w] = m;
    path[i][j][k][w] = optm;
    return m;
}
    
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    memset(memo, -1, sizeof(memo));
    
    for (int i = 0; i < 20; ++i) {
        for (int j: {0, 1}){
            for (int k: {0, 1}) {
                for (int w: {0,1 }) {
                    path[i][j][k][w] = {-1, -1, -1, -1};
                }
            }
        }
    }
    
    ll a, b; cin >> a >> b;
    
    string sa = to_string(a);
    string sb = to_string(b);
    
    vector<int> da(sb.size());
    
    int diff = sb.size() - sa.size();
    
    for (int i = 0; i < diff; ++i) da[i] = 0;
    
    for (int i = diff; i < sb.size(); ++i) da[i] = sa[i-diff] - '0';
    
    vector<int> db(sb.size());
    
    for (int i = 0; i < sb.size(); ++i) db[i] = sb[i] - '0';
    
    
    ll v = solve(da, db, 0, 1, 1, 0);

    if (v == 0) {
        cout << a << endl;
        return 0;
    }
    
    Node root = {-1, -1, -1, -1};
    
    for (int j:{0, 1}) {
        for (int k:{0,1}) {
            for (int w:{0, 1}) {
                if (memo[0][j][k][w] == v) {
                    root = path[0][j][k][w];
                    break;
                } 
            }
        }
    }
    
    vector<ll> ans;
    ans.push_back(v);
    
    while (root.i != -1 && root.j != -1 && root.k != -1 && root.w != -1) {
        ans.push_back(memo[root.i][root.j][root.k][root.w]);
        root = path[root.i][root.j][root.k][root.w];
    }
    
    vector<int> digits;
    ll cur = 1;
    
    for (int i = ans.size() - 1; i >= 0; --i) {
        for (int x = 1; x <= 9; ++x) {
            if (x * cur == ans[i]) {
                
                string s = "";
    
                s+=to_string(x);
    
                for (int i = digits.size() - 1; i >= 0; --i) {
                    s+=to_string(digits[i]);
                }
                
                if (s.size() >= 19) {
                    i = -1;
                    break;
                }
                
                ll val = stoull(s);
                if (val > b) break;
                
                digits.push_back(x);
                cur *= x;
                
                if (cur == v && cur >= a && cur <= b) {
                    i = -1;
                    break;
                }
            }
        }        
    }
    
    string s = "";
    
    for (int i = digits.size() - 1; i >= 0; --i) {
        s+=to_string(digits[i]);
    }
    
    cout << s << endl;
    
}
