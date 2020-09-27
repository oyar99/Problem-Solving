#include <bits/stdc++.h>
    
using namespace std;

struct SuffixAutomaton {
  vector<map<char,int>> edges; 
  vector<int> link;            
  vector<int> length;          
  int last;                    

  SuffixAutomaton(string s) {
    
    edges.push_back(map<char,int>());
    link.push_back(-1);
    length.push_back(0);
    last = 0;

    for(int i=0;i<s.size();i++) {
      
      edges.push_back(map<char,int>());
      length.push_back(i+1);
      link.push_back(0);
      int r = edges.size() - 1;

      
      int p = last;
      while(p >= 0 && edges[p].find(s[i]) == edges[p].end()) {
        edges[p][s[i]] = r;
        p = link[p];
      }
      if(p != -1) {
        int q = edges[p][s[i]];
        if(length[p] + 1 == length[q]) {
          
          link[r] = q;
        } else {
          
          edges.push_back(edges[q]); 
          length.push_back(length[p] + 1);
          link.push_back(link[q]); 
          int qq = edges.size()-1;
          
          link[q] = qq;
          link[r] = qq;
          
          while(p >= 0 && edges[p][s[i]] == q) {
            edges[p][s[i]] = qq;
            p = link[p];
          }
        }
      }
      last = r;
    }
  }
};
    
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string C; cin >> C;
    SuffixAutomaton a(C);
    int N; cin >> N;
    
    for (int i = 0; i < N;++i) {
        string F; cin >> F;
        
        int n = 0;
        int count = 1;
        bool pos = true;
        for (int i = 0; i < F.size(); ++i) {
            if (a.edges[n].find(F[i]) == a.edges[n].end()) {
                ++count;
                if (n == 0) {
                    pos = false;
                    break;
                }

                n = 0;
                --i;
            } else {
                n = a.edges[n][F[i]];
            }
        }

        if (pos) cout << count << endl;
        else cout << -1 << endl;
    }
}