#pragma optimize("O3")

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; 

    vector<int> primes;
    primes.reserve(4000);

    primes.push_back(2);
    int p = 3;
    while (primes.size() < 3502) {
        
        bool prime = true;
        for (int i = 3; i <= sqrt(p); ++i) {
            if (p % i == 0) {
                prime = false;
                break;
            }
        }

        if (prime) primes.push_back(p);

        p += 2;
    }

    while (1) {
        cin >> n;

        if (n == 0) break;

        list<int> people;

        for (int i = 1; i <= n; ++i) people.push_back(i);

        int i = 0;
        list<int>::iterator it = people.begin();
        while (people.size() > 1) {

            int d = distance(people.begin(), it);

            int move = ((d + primes[i]) % people.size()) - d - 1;

            for (int i = 0; i < abs(move); ++i) {
                if (move < 0) {
                    if (it == people.begin()) it = --people.end();
                    else it = prev(it, 1);
                } else {
                    if (next(it, 1) == people.end()) it = people.begin();
                    else it = next(it, 1);
                }
            }

            list<int>::iterator temp;

            if (next(it, 1) == people.end()) temp = people.begin();
            else temp = next(it, 1);

            people.erase(it);
            it = temp;

            ++i;
        }

        cout << *people.begin() << endl;
        
    }


}
