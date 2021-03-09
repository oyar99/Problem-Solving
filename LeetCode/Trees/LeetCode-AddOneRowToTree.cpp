class Solution {
public:
    TreeNode* depth(TreeNode* node, int cd, int d, int v, TreeNode* root) {
        if (d == 0) {
            TreeNode * newRoot = new TreeNode(v);
            newRoot->left = node;
            return newRoot;
        }
        
        if (cd == d) {
            TreeNode * left = new TreeNode(v);
            TreeNode * right = new TreeNode(v);
            
            left->left = node->left;
            right->right = node->right;
            node->left = left;
            node->right = right;
            return root;
        }
        
        if (node->left != nullptr) depth(node->left, cd + 1, d, v, root);
        
        if (node->right != nullptr) depth(node->right, cd + 1, d, v, root);
        
        return root;
    }
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        return depth(root, 1, d - 1, v, root);   
    }
};
