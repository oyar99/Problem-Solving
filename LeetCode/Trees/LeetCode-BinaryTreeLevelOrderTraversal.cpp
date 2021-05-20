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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        if (!root) return {};
        
        vector<vector<int>> ans;
        
        queue<TreeNode*> q;
        map<TreeNode*, int> h;
        h[root] = 0;
        q.push(root);
        
        while (!q.empty()) {
            TreeNode * u = q.front();
            q.pop();
            
            if (h[u] >= ans.size()) {
                ans.push_back({u->val});
            } else {
                ans[h[u]].push_back(u->val);
            }
            
            if (u->left) {
                q.push(u->left);
                h[u->left] = h[u] + 1;
            }
            
            if (u->right) {
                q.push(u->right);
                h[u->right] = h[u] + 1;
            }
        }
        
        return ans;
    }
};
