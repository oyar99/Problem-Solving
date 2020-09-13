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
private:
    void get_height(TreeNode* root, unordered_map<TreeNode*, int>& height) {
        if (root == nullptr) return;
        

        get_height(root->left, height);
        get_height(root->right, height);
        height[root] = max(height[root->left], height[root->right]) + 1;
    }
    
    TreeNode * LCA(TreeNode* root, unordered_map<TreeNode*, int>& height) {
        
        if (height[root->left] == height[root->right]) return root;
        
        if (height[root->left] > height[root->right]) return LCA(root->left, height);
        
        return LCA(root->right, height);
    }
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        unordered_map<TreeNode*, int> height;
        height[nullptr] = 0;
        get_height(root, height);
        
        
        return LCA(root, height);
    }
};
