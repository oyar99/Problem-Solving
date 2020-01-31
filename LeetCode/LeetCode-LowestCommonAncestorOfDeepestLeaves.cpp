class Solution {
    
    int deep(TreeNode* n) {
        if (n == NULL) return 0;
        
        return max(deep(n->left) + 1, deep(n->right) + 1);
    }
    
    void get_deepest_leaves(TreeNode* n, int d, int t, vector<TreeNode*>& out) {
        if (n == NULL) return;
        
        if (d == t) out.push_back(n);
        
        get_deepest_leaves(n->left, d + 1, t, out);
        get_deepest_leaves(n->right, d + 1, t, out);
    }
    
    void map_parents(TreeNode* n, TreeNode* parent, unordered_map<TreeNode*, TreeNode*>& m) {
        
        if (n == NULL) return;
        
        m[n] = parent;
        map_parents(n->left, n, m);
        map_parents(n->right, n, m);
    }
    
    TreeNode* lca(TreeNode* a, TreeNode* b, unordered_map<TreeNode*, TreeNode*>& m) {
        unordered_set<TreeNode*> s;
        
        TreeNode* parent = m[a];
        
        while (parent != NULL) s.insert(parent), parent = m[parent];
        
        parent = b;
        
        while (s.count(parent) <= 0) parent = m[parent];
        
        return parent;
    }
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        vector<TreeNode*> leaves;
        unordered_map<TreeNode*, TreeNode*> m;
        
        get_deepest_leaves(root, 1, deep(root), leaves);
        map_parents(root, NULL, m);
        
        TreeNode * c = leaves.front();
        for (int i = 1; i < leaves.size(); ++i) c = lca(leaves[i], c, m);
        
        return c;
    }
};
