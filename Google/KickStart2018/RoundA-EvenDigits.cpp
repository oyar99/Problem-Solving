#include <bits/stdc++.h>
#define int long long
using namespace std;

int add(int a, int b) {
	return a + b;
}

int subs(int a, int b) {
	return a - b;
}

int count_moves(string& n, int l, int (*op)(int, int), bool subb) {
	string sub = n.substr(l, n.size() - l);
	int val = stol(sub);
	int v1 = op(stol(sub.substr(0, 1)), 1) % 10;
	ostringstream ss;
	ss << v1;
	string temp = ss.str();
	sub[0] = temp[0];
	if (subb) {
		for (int i = 1; i < sub.size(); ++i) {
			if (sub[0] == '0' && i == 1) sub[i] = '8';
			else sub[i] = '8';
		}
	}
	else {
		bool done = false;
		for (int i = 1; i < sub.size(); ++i) {
			if (sub[0] == '0' && !done) { 
				sub = '2' + sub;
				done = true;
				--i;
			}
			else sub[i] = '0';
		}
	}
	int newVal = stol(sub);
	return abs(newVal - val);
}

int find_moves(string& n) {
	int moves = 0;
	for (int i = 0; i < n.size(); ++i) {
		if (!((n[i] - '0') & 1)) continue;
		moves += min(count_moves(n, i, add, false), count_moves(n, i, subs, true));
		break;
	}
	return moves;
}

int find_ans() {
	string n;
	cin >> n;
	return find_moves(n);
}

#undef int
int main() {
	#define int long long
	int T;
	cin >> T;
	for (int i = 0; i < T;++i) {
		int ans = find_ans();
		cout << "Case #" << (i+1) << ": " << ans << endl;
	}
}