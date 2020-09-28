#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

class graph {
    public:
        unordered_map<int, unordered_map<int, int>> list;

        unordered_map<int, int> get_neighbours(int u) {
            return list[u];
        }
};

class Tree {
public:
    int id;
    int depth;
    pair<Tree*, int> parent;
    vector<pair<Tree*, int>> children;
};

class Compare {
    public:
    bool operator() (const pair<int, pair<int, int>>& a, const pair<int, pair<int, int>>& b) {
        return a.second.second > b.second.second;
    }
};


pair<graph, int> minimum_spanning_tree(graph& g, int u) {
    graph tree;
    int weight = 0;

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, Compare> q;
    while (g.list.size() != tree.list.size()) {
        for (auto& v: g.get_neighbours(u)) {
            if (tree.list.count(v.first) > 0) continue;
            q.push({u, {v.first, v.second}});
        }

        auto w = q.top();
        q.pop();
        
        if (tree.list.count(w.first) > 0 && tree.list.count(w.second.first) > 0) continue;
        
        tree.list[w.first][w.second.first] = w.second.second;
        tree.list[w.second.first][w.first] = w.second.second;
        weight += w.second.second;
        u = w.second.first;
    }
    return {tree, weight};
}


Tree* graph_to_tree(graph& g, int root, vector<Tree*>& nodes) {
    Tree* tree = new Tree();
    queue<pair<Tree*,int>> q;
    unordered_set<int> visited;
    q.push({tree,root});
    visited.insert(root);
    while (!q.empty()) {
        int w = q.front().second;
        Tree* t = q.front().first;
        t->id = w;
        nodes[w] = t;
        q.pop();
        for (auto& n: g.get_neighbours(w)) {
            if (visited.count(n.first) <= 0) {
                visited.insert(n.first);
                Tree* sub = new Tree();
                sub->id = n.first;
                if (sub->id == root) {
                    tree->depth = 0;
                    sub->parent.first = nullptr;
                }
                else { 
                    sub->parent.first = t;
                    sub->parent.second = n.second;
                    sub->depth = t->depth + 1;
                }
                t->children.push_back({sub, n.second});
                q.push({sub, n.first});
            }
        }
    }
    return tree;
}

void build_euler_tour(Tree* t, vector<pair<int, int>>& out_table, vector<int>& leaves) {
    stack<Tree*> s;
    unordered_set<int> visited;
    unordered_map<int, int> inds;
    int height = 0;
    s.push(t);
    visited.insert(t->id);
    while (!s.empty()) {
        auto v = s.top();

        if (inds.count(v->id) <= 0) {
            out_table.push_back({v->id, height});
            inds[v->id] = height;
        }
        else {
            out_table.push_back({v->id, inds[v->id]});
        }


        bool all = true;
        for (auto& child: v->children) {
            if (visited.count(child.first->id) <= 0) {
                visited.insert(child.first->id);
                s.push(child.first);
                all = false;
                break;
            }
        } 

        if (all) {
            s.pop();
            leaves.push_back(v->id);
        }
        ++height;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, R;
    cin >> N >> R;
    graph g;

    for (int i = 0; i < R;++i) {
        int u, v, c;
        cin >> u >> v >> c;
        g.list[u][v] = c;
        g.list[v][u] = c;
    }

    auto tree = minimum_spanning_tree(g, 1);
    vector<Tree*> nodes(tree.first.list.size() + 1, nullptr);
    Tree* t = graph_to_tree(tree.first, 1, nodes);
    vector<pair<int, int>> euler_table;
    vector<int> first_ocurrence(tree.first.list.size() + 1, -1);
    vector<int> leaves;
    build_euler_tour(t, euler_table, leaves);
    vector<vector<int>> sparse_table(ceil(log2(euler_table.size()) + 1), vector<int>(euler_table.size() + 1));
    vector<vector<int>> sparse_table_dists(ceil(log2(tree.first.list.size()) + 1), vector<int>(tree.first.list.size() + 1));
    vector<vector<int>> sparse_table_ances(ceil(log2(tree.first.list.size()) + 1), vector<int>(tree.first.list.size() + 1));
    unordered_map<int, int> map;
    vector<int> logs(N+1);

    logs[1] = 0;
    for (int i = 2; i <= N; ++i) {
        logs[i] = logs[i / 2] + 1;
    }
    
    for (int i = 0; i < euler_table.size();++i) {
        sparse_table[0][i] = euler_table[i].second;
        map[euler_table[i].second] = euler_table[i].first;

        if (first_ocurrence[euler_table[i].first] != -1) continue;
        first_ocurrence[euler_table[i].first] = i;
    }
    
    for (int i = 1; i < sparse_table.size(); ++i) {
        for (int j = 0; j + (1 << i) <= sparse_table[i].size();++j) {
            sparse_table[i][j] = min(sparse_table[i - 1][j], sparse_table[i - 1][j + (1 << (i - 1))]);
        }
    }
    
    auto t1 = chrono::high_resolution_clock::now();
    unordered_set<int> visited;
    for (int u = 0; u < leaves.size(); ++u) {
        int w = leaves[u];
        vector<int> ancestor;
        vector<int> path;
        vector<int> nodes_vis;
        while (nodes[w]->parent.first != nullptr) {
            path.push_back(nodes[w]->parent.second);
            ancestor.push_back(nodes[w]->parent.first->id);
            nodes_vis.push_back(w);
            visited.insert(w);
            w = nodes[w]->parent.first->id;
        }
        for (int i = 0; i < path.size(); ++i) {
            sparse_table_dists[0][nodes_vis[i]] = path[i];
            sparse_table_ances[0][nodes_vis[i]] = ancestor[i];
        }

        for (int i = 1; i < ceil(log2(path.size())) + 1;++i) {
            for (int j = 0; j + (1 << i) <= path.size(); ++j) {
                sparse_table_dists[i][nodes_vis[j]] = max(sparse_table_dists[i-1][nodes_vis[j]], sparse_table_dists[i-1][nodes_vis[j + (1 << (i-1))]]);
                sparse_table_ances[i][nodes_vis[j]] = sparse_table_ances[i-1][nodes_vis[j + (1 << (i-1))]];
            }
        }
    }
    auto t2 = chrono::high_resolution_clock::now();
    int duration = chrono::duration_cast<chrono::milliseconds>(t2 - t1).count();
    cout << "PREPROCESSING: " << duration << " milliseconds" << endl;

    int Q;
    cin >> Q;
    for (int i = 0; i < Q;++i) {
        int u, v;
        cin >> u >> v;

        if (tree.first.list[u].count(v) > 0) {
            cout << tree.second << endl;
        }
        else {

            int index_u = first_ocurrence[u];
            int index_v = first_ocurrence[v];

            if (index_u > index_v) {
                swap(index_u, index_v);
            }

            index_v += 1;
            int log_ = floor(log2(index_v - index_u));
            int suffix = 1 << log_;
            int lca = min(sparse_table[log_][index_u], sparse_table[log_][index_v - suffix]);

            
            int max_u = 0;
            int max_v = 0;
            int s = u;
            int r = v;

            while (nodes[s]->depth != nodes[map[lca]]->depth) {
                max_u = max(max_u, sparse_table_dists[logs[(nodes[s]->depth - nodes[map[lca]]->depth)]][s]);  
                s = sparse_table_ances[logs[(nodes[s]->depth - nodes[map[lca]]->depth)]][s];
            }
            
            while (nodes[r]->depth != nodes[map[lca]]->depth) {
                max_v = max(max_v, sparse_table_dists[logs[(nodes[r]->depth - nodes[map[lca]]->depth)]][r]);
                r = sparse_table_ances[logs[(nodes[r]->depth - nodes[map[lca]]->depth)]][r];     
            }
            
            int max_cost = max(max_u, max_v);
            cout << tree.second - max_cost + g.list[u][v] << endl;
        }
    }
}
