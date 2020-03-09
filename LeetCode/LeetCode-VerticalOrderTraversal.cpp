struct Point {
    int x;
    int y;
};

class Solution {
    void dfs(TreeNode * root, vector<pair<Point, int>>& out, int x, int y) {
        if (root == NULL) return;
        
        out.push_back({{x, y}, root->val});
        dfs(root->left, out, x - 1, y - 1);
        dfs(root->right, out, x + 1, y - 1);
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<pair<Point, int>> points;
        dfs(root, points, 0, 0);
        
        sort(points.begin(), points.end(), [](const pair<Point, int>& a, const pair<Point, int>& b) {
            if (a.first.x == b.first.x) {
                if (a.first.y == b.first.y) return a.second < b.second;
                return a.first.y > b.first.y;
            }
            
            return a.first.x < b.first.x;
        });
        
        vector<vector<int>> ans;
        vector<int> v;
        v.push_back(points[0].second);
        for (int i = 1; i < points.size(); ++i) {
            if (points[i-1].first.x == points[i].first.x) {
                v.push_back(points[i].second);
            } else {
                vector<int> t(v);
                ans.push_back(t);
                v.clear();
                v.push_back(points[i].second);
            }
        }
        ans.push_back(v);
        
        return ans;
        
    }
};
