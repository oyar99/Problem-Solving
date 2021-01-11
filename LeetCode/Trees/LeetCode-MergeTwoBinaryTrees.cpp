class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t1 == nullptr && t2 == nullptr) return nullptr;
        
        TreeNode * left = mergeTrees(t1 == nullptr ? nullptr : t1->left, t2 == nullptr ? nullptr : t2->left);
        TreeNode * right = mergeTrees(t1 == nullptr ? nullptr : t1->right, t2 == nullptr ? nullptr : t2->right);
        
        int sum = 0;
        
        if (t1 != nullptr) sum += t1->val;
        if (t2 != nullptr) sum += t2-> val;
        
        TreeNode * head = new TreeNode(sum);
        head->left = left;
        head->right = right;
        
        return head;
    }
};
