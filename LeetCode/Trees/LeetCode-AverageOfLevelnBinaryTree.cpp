
class Solution {
    vector<double> bfs(TreeNode* root) {
        queue<TreeNode*> q;
        vector<double> out(1000);
        vector<int>count(1000);
        q.push(root);
        unordered_map<TreeNode*, int> L;
        L[root] = 0;
        
        while (!q.empty()) {
            TreeNode * u = q.front();
            out[L[u]] += u->val;
            count[L[u]]++;
            q.pop();

            if (u->left != NULL) {
                q.push(u->left);
                L[u->left] = L[u] + 1;
            }
            
            if (u->right != NULL) {
                q.push(u->right);
                L[u->right] = L[u] + 1;
            }
        }
        
        vector<double> ans;
        
        for (int i = 0; i < 1000; ++i) {
            if (count[i] == 0) continue;
            ans.push_back(out[i] / count[i]);
        }
        
        return ans;
    }
    
public:
    vector<double> averageOfLevels(TreeNode* root) {
        return bfs(root);
    }
};
