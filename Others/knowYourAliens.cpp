#include <string>
#include <vector>
#include <iostream>

using namespace std;

#define int long long

class polynomial {
    public:

        vector<int> bases;

        polynomial(vector<int> b) {
            bases = b;
        }

        polynomial operator *(const polynomial& p) {
            vector<int> b(bases.size() + 1);

            for (int i = 0; i < p.bases.size(); ++i) {
                for (int j = 0; j < bases.size(); ++j) {
                    b[i+j] += bases[j] * p.bases[i];
                }
            }
            return polynomial(b);
        } 
};

#undef int
int main() {
    #define int long long
    string N;
    getline(cin, N);

    vector<polynomial> p;

    int positive = N.back() == 'H' ? 1:-1;
    
    for (int i = 4; i <= 2 * N.size(); i+= 2) {
        if (N[(i / 2) - 1] != N[((i-2) / 2) - 1]) p.push_back(vector<int> {1, -(i-1)});
    }

    cout << p.size() << endl;

    if (p.size() > 0) {
        polynomial result = p.front();
        for (int i = 1; i < p.size();++i) result = result * p[i];

        for (int i = 0; i < result.bases.size(); ++i) {
            if (i + 1 == result.bases.size()) cout << positive * result.bases[i];
            else cout << positive * result.bases[i] << " ";
        }

    } else {
        cout << positive;
    }
    cout << endl;
    return 0;
}