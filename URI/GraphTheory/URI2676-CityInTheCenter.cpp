#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <vector>
#include <functional>
#include <iostream>
#include <algorithm>
#include <stack>


using namespace std;

class graph {
    private:
        vector<vector<int>> matrix;
    public:

        graph(int s) {
            matrix = vector<vector<int>>(s, vector<int>(s));
        }

        void add_edge(int u, int v, int c) {
            matrix[u][v] = c;
            matrix[v][u] = c;
        }

        int get_edge(int u, int v) {
            return matrix[u][v];
        }

        int num_vertices() {
            return matrix.size();
        }
};

vector<int> floyd_warshall(graph& g) {

    vector<vector<int>> R(g.num_vertices(), vector<int>(g.num_vertices()));

    for (int i = 1; i < R.size();++i) {
        for (int j = 1; j < R.size();++j) {
            R[i][j] = g.get_edge(i, j) == 0 ? 1000: g.get_edge(i, j);
        }
    }

    for (int k = 1; k < g.num_vertices(); ++k) {
        for (int i = 1; i < g.num_vertices();++i) {
            for (int j = 1; j < g.num_vertices();++j) {
                if (i == j || i == k || j == k) continue;
                R[i][j] = min(R[i][j], R[i][k] + R[k][j]);
            }
        }
    }

    int min_sum = INT32_MAX;
    vector<int> mins;

    for (int i = 1; i < R.size();++i) {
        int sum = 0;
        for (int j = 1; j < R.size();++j) {
            if (i == j) continue;
            sum += R[i][j];
        }

        if (sum < min_sum) {
            min_sum = sum;
            mins.clear();
            mins.push_back(i);
        } else if (min_sum == sum) {
            mins.push_back(i);
        }
    }

    return mins;
}

int main() {
    int N, R;
    
    while (true) {
        cin >> N >> R;

        if (N == 0 and R == 0) break;

        graph g(N + 1);

        for (int i = 0; i < R; ++i) {
            int a, b, d;
            cin >> a >> b >> d;

            g.add_edge(a, b, d);
        }

        vector<int> out = floyd_warshall(g);

        for (auto e: out) cout << e << " ";
        cout << endl;

    }
}
