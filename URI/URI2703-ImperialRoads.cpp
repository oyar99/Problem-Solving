#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

struct pair_hash {
	template <class T1, class T2>
	std::size_t operator () (const std::pair<T1, T2>& p) const {
		auto h1 = std::hash<T1>{}(p.first);
		auto h2 = std::hash<T2>{}(p.second);

		return h1 ^ h2;
	}
};

class graph {
    public:
        unordered_map<int, unordered_map<int, int>> list;
    
        void add_vertex(int u) {
            list.insert({u, unordered_map<int, int>()});
        }

        void add_edge(int u, int v, int c) {
            list[u].insert({v, c});
            list[v].insert({u, c});
        }

        void remove_edge(int u, int v) {
            list[u].erase(v);
            list[v].erase(u);
        }

        int num_vertices() {
            return list.size();
        }

        bool is_adjacent(int u, int v) {
            return list[u].count(v) > 0;
        }

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


pair<graph, int> minimum_spanning_tree(graph& g, int u) {
    graph tree;
    int w = 0;
    unordered_set<pair<int, int>, pair_hash> edges_added;
    vector<pair<int, pair<int, int>>> edges;
    tree.add_vertex(u);
    while (g.num_vertices() != tree.num_vertices()) {
        for (auto n: g.get_neighbours(u)) {
            
            if (edges_added.count({u, n.first}) > 0 || edges_added.count({n.first, u})) continue;
            if (tree.list.count(n.first) > 0) continue;
            edges.push_back({u, {n.first, n.second}});
            push_heap(edges.begin(), edges.end(), [](const pair<int, pair<int, int>>& a, const pair<int, pair<int, int>>& b) {return a.second.second > b.second.second;});
        }
        pair<int, pair<int, int>> min_edge;
        min_edge = edges.front();
        pop_heap(edges.begin(), edges.end(), [](const pair<int, pair<int, int>>& a, const pair<int, pair<int, int>>& b) {return a.second.second > b.second.second;});
        edges.pop_back();
        if (tree.list.count(min_edge.first) > 0 && tree.list.count(min_edge.second.first) > 0) continue;
        tree.add_vertex(min_edge.first);
        tree.add_vertex(min_edge.second.first);
        tree.add_edge(min_edge.first, min_edge.second.first, min_edge.second.second);
        w += min_edge.second.second;
        edges_added.insert({min_edge.first, min_edge.second.first});
        u = min_edge.second.first;
    }
    return {tree, w};
}


Tree* graph_to_tree(graph& g, int root, vector<Tree*>& nodes) {
    Tree* tree = new Tree();
    queue<pair<Tree*,int>> q;
    unordered_set<int> visited;
    q.push({tree,root});

    while (!q.empty()) {
        int w = q.front().second;
        Tree* t = q.front().first;
        t->id = w;
        nodes[w] = t;
        q.pop();
        visited.insert(w);
        for (auto n: g.get_neighbours(w)) {
            if (visited.count(n.first) <= 0) {
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


int build_euler_tour(Tree * t ,vector<pair<int, int>>& out_table, int height) {
    if (t->children.empty()) { 
        out_table.push_back({t->id,height}); 
    } else {
        out_table.push_back({t->id, height});
        int fixed_h = height;
        for (auto child: t->children) {
            ++height;
            height = build_euler_tour(child.first, out_table, height);
            out_table.push_back({t->id, fixed_h});
        }
    }
    return height;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, R;
    cin >> N >> R;
    graph g;
    for (int i = 1; i <= N;++i) {
        g.add_vertex(i);
    }

    for (int i = 0; i < R;++i) {
        int u, v, c;
        cin >> u >> v >> c;
        g.add_edge(u, v, c);
    }
    auto t1 = chrono::high_resolution_clock::now();
    auto tree = minimum_spanning_tree(g, 1);
    auto t2 = chrono::high_resolution_clock::now();
    auto dur = chrono::duration_cast<chrono::milliseconds>(t2 - t1).count();
    cout << "SPANNING TREE: " << dur << endl;
    vector<Tree*> nodes(tree.first.num_vertices() + 1, nullptr);
    Tree* t = graph_to_tree(tree.first, 1, nodes);
    vector<pair<int, int>> euler_table;
    vector<int> first_ocurrence(tree.first.num_vertices() + 1, -1);
    build_euler_tour(t, euler_table, 0);
    vector<vector<int>> sparse_table(ceil(log2(euler_table.size()) + 1), vector<int>(euler_table.size() + 1));
    vector<vector<int>> sparse_table_dists(ceil(log2(tree.first.num_vertices()) + 1), vector<int>(tree.first.num_vertices() + 1));
    vector<vector<int>> sparse_table_ances(ceil(log2(tree.first.num_vertices()) + 1), vector<int>(tree.first.num_vertices() + 1));
    unordered_map<int, int> map;
    vector<int> logs(N+1);

    logs[1] = 0;
    for (int i = 2; i <= N; ++i) {
        logs[i] = logs[i / 2] + 1;
    }

    for (auto e: euler_table) {
        map[e.second] = e.first;
    }

    for (int i = 0; i < euler_table.size();++i) {
        if (first_ocurrence[euler_table[i].first] != -1) continue;
        first_ocurrence[euler_table[i].first] = i;
    }
    
    for (int i = 0; i < euler_table.size();++i) {
        sparse_table[0][i] = euler_table[i].second;
    }


    for (int i = 1; i < sparse_table.size(); ++i) {
        for (int j = 0; j + (1 << i) <= sparse_table[i].size();++j) {
            sparse_table[i][j] = min(sparse_table[i - 1][j], sparse_table[i - 1][j + (1 << (i - 1))]);
        }
    }

    unordered_set<int> visited;
    for (int u = 1; u <= N; ++u) {

        if (visited.count(u) > 0) continue;

        int w = u;
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
