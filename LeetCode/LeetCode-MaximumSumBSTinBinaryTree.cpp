
class Solution {
    
    void isBST(TreeNode* root, unordered_map<TreeNode*, bool>& nodes) {
        
        if (root == NULL) return;
        
        if (root->left == NULL && root->right == NULL) {
            nodes[root] = true;
            return;
        }
        
        bool may = true;
        
        if (root->left != NULL) {
            if (root->left->val >= root->val) {
                nodes[root] = false;
                may = false;
            }
        }
        if (root->right != NULL) {
            if (root->right->val <= root->val) {
                nodes[root] = false;
                may = false;
            }
        }
        
        
        isBST(root->left, nodes);
        isBST(root->right, nodes);
        
        if (may) nodes[root] = nodes[root->left] && nodes[root->right];
        
    }
    
    
    int sum(TreeNode * node, unordered_map<TreeNode*, int>& S) {
        if (node == NULL) return 0;
        
        int val = node->val + sum(node->left, S) + sum(node->right, S);
        S[node] = val;
        return val;
    }
    
    void findBST(TreeNode * root, unordered_map<TreeNode*, bool>& nodes, vector<TreeNode*>& bsts) {
        if (root == NULL) return;
        
        if (nodes[root]) bsts.push_back(root);
        
        findBST(root->left, nodes, bsts);
        findBST(root->right, nodes, bsts);
    }
    
public:
    int maxSumBST(TreeNode* root) {
        unordered_map<TreeNode*, bool> nodes;
        nodes[NULL] = true;
        isBST(root, nodes);
        unordered_map<TreeNode*, int> S;
        sum(root, S);
        vector<TreeNode*> bsts;
        findBST(root, nodes, bsts);
        
        int m = 0;
        
        for (int i = 0; i < bsts.size(); ++i) m = max(m, S[bsts[i]]);
        
        return m;
    }
};
