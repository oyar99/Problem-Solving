#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n; cin >> n;
    vector<int> numbers(n);
    for (int i = 0; i < n;++i) {
        int e; cin >> e;
        numbers[i] = e;
    }

    sort(numbers.begin(), numbers.end());

    cout << numbers[(n & 1 ? n/2:n/2-1)] << endl;

    return 0;
}