class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // Adjacency list of course prerequisites
        // This representation of the graph is not modifed throughout this function
        vector<unordered_set<int>> adj(numCourses, unordered_set<int>(numCourses));
        vector<int> incoming_edges(numCourses, 0);
        
        // Create the graph with the corresponding edges
        // Compute the in-degree of each vertex
        for (const auto& edge: prerequisites) {
            adj[edge[1]].insert(edge[0]);
            ++incoming_edges[edge[0]];
        }
        
        // The topological ordering
        vector<int> order;
        // The list of vertices which have in-degree 0
        set<int> to_be_deleted;
        
        for (int u = 0; u < numCourses; ++u)
            if (incoming_edges[u] <= 0) to_be_deleted.insert(u);
        
        while (to_be_deleted.size() > 0) {
            int u = *to_be_deleted.begin();
            
            order.push_back(u);
            to_be_deleted.erase(to_be_deleted.begin());
            
            // Update the in-degree of all adjacent vertices
            for (int v : adj[u]) {
                --incoming_edges[v];
                
                if (incoming_edges[v] <= 0) {
                    to_be_deleted.insert(v);
                }
            }
        }
        
        // Determine if all edges were deleted
        for (int u = 0; u < numCourses; ++u)
            if (incoming_edges[u] > 0) return vector<int>();
        
        return order;
    }
};
