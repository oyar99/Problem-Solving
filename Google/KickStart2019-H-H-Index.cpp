#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int T; cin >> T;
    for (int t = 0; t < T;++t) {
        int n; cin >> n;
        vector<int> papers;
        int h = 0;
        cout << "Case #" << t+1 << ": ";
        for (int i = 0; i < n;++i) {
            int p; cin >> p;
            if (p > h) {
                papers.push_back(p);
                push_heap(papers.begin(), papers.end(), greater<int>());
                while (papers.front() <= h) {
                    pop_heap(papers.begin(), papers.end(), greater<int>());
                    papers.pop_back();
                }
                if (papers.size() > h) ++h;
            }
            if (i + 1 != n) cout << h << " ";
            else cout << h << endl;
        }
    }
    return 0;
}