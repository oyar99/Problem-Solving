/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        vector<int> m(6001, -1);
        
        int n = inorder.size();
        
        for (int i = 0; i < n; ++i) {
            m[inorder[i] + 3000] = i;
        }
        
        return buildTree(preorder, inorder, m, 0, 0, preorder.size() - 1);
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, vector<int>& m, int px, int l, int r) {
        int n = preorder.size();
        
        if (l > r) {
            return nullptr;
        }
        
        TreeNode * root = new TreeNode(preorder[px]);
        
        int x = m[root->val + 3000];
        
        root->left = buildTree(preorder, inorder, m, px + 1, l, x - 1);
        
        root->right = buildTree(preorder, inorder, m, px + 1 + (x - l), x + 1, r);
        
        return root;
    }
};
