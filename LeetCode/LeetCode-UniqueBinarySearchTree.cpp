//O(n! * nlgn)
class Solution {
    void insert(TreeNode* root, int val) {
        if (val > root->val) {
            if (root->right != NULL) insert(root->right, val);
            else root->right = new TreeNode(val);
        }
        else {
            if (root->left != NULL) insert(root->left, val);
            else root->left = new TreeNode(val);
        }
    }
    
    void preorder(TreeNode* root, string& s) {
        if (root == NULL) {
            s += "#";
            s += " ";
            return;
        }
        
        s += to_string(root->val);
        s += " ";
        preorder(root->left, s);
        preorder(root->right, s);
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        vector<int> A(n);
        
        for (int i = 0; i < n;++i) A[i] = i + 1;
        
        vector<TreeNode*> trees;
        unordered_set<string> U;
        do {
            TreeNode * root = new TreeNode(A[0]);
            for (int i = 1; i < n; ++i) insert(root, A[i]);
            
            string s = "";
            preorder(root, s);
            if (U.count(s) <= 0) {
                U.insert(s);
                trees.push_back(root);
            }
            
        } while (next_permutation(A.begin(), A.end()));
        return trees;
    }
};
