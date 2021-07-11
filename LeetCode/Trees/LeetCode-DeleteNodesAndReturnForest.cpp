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
    void dfs(TreeNode*& node, unordered_set<int>& to_delete, vector<TreeNode*>& forest, bool shouldAdd = false) {
        if (node == nullptr) return;
        
        if (to_delete.count(node->val) > 0) {            
            dfs(node->left, to_delete, forest, true);
            dfs(node->right, to_delete, forest, true);
            
            delete node;
            node = nullptr;
            return;
        } else if (shouldAdd) {
            forest.push_back(node);
        }
        
        dfs(node->left, to_delete, forest);
        dfs(node->right, to_delete, forest);
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> to_delete_set;
        
        for (int x : to_delete) {
            to_delete_set.insert(x);
        }
        
        vector<TreeNode*> result;
        
        dfs(root, to_delete_set, result, true);
        
        return result;
    }
};
