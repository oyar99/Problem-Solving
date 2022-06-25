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
struct Q {
private:
    vector<vector<int>> matrix;
    vector<int> logs;
public:
    Q(vector<int>& nums) {
        int n = nums.size();
        
        logs = vector<int>(n + 1, 0);
        for (int i = 2; i <= nums.size(); ++i) {
            logs[i] = logs[i / 2] + 1;
        }
        
        matrix = vector<vector<int>>(n, vector<int>(logs[n] + 1, 0));
        
        for (int i = 0; i < n; ++i) {
            matrix[i][0] = nums[i];
        }
        
        for (int j = 1; j < logs[n] + 1; ++j) {
            for (int i = 0; i - 1 + (1 << (j)) < n; ++i) {
                matrix[i][j] = max(matrix[i][j-1], matrix[i + (1 << (j-1))][j-1]);
            }
        }
    }
    
    int query_max(int l, int r) {
        int length = logs[r - l + 1];
        return max(matrix[l][length], matrix[r - (1 << length) + 1][length]);
    }
};

class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums, Q& q, map<int, int>& m, int l, int r) {
        if (l > r) {
            return nullptr;
        }
        
        int val = q.query_max(l, r);
        int pos = m[val];
        
        TreeNode* node = new TreeNode(val);
        
        node->left = constructMaximumBinaryTree(nums, q, m, l, pos - 1);
        node->right = constructMaximumBinaryTree(nums, q, m, pos + 1, r);
        
        return node;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        Q q(nums);
        
        map<int, int> m; // map value to its index
        
        for (int i = 0; i < nums.size(); ++i) {
            m[nums[i]] = i;
        }
        
        
        return constructMaximumBinaryTree(nums, q, m, 0, nums.size() - 1);
    }
};
