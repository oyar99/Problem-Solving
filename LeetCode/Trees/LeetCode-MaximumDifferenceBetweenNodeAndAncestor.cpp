/*
Time: O(N)
*/
class Solution {
    int max(int a, int b, int c, int d) {
        return ::max(::max(a,  b), ::max(c, d));
    }
public:
    int dfs(TreeNode* node, int minValue, int maxValue) {
        
        if (node == nullptr) return INT32_MIN;
        
        minValue = min(minValue, node->val);
        maxValue = ::max(maxValue, node->val);
        
        return max(abs(node->val - minValue), 
                   abs(node->val - maxValue), 
                   dfs(node->left, minValue, maxValue), 
                   dfs(node->right, minValue, maxValue));
    }
    int maxAncestorDiff(TreeNode* root) {
        return dfs(root, INT32_MAX, INT32_MIN);
    }
};
