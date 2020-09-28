class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        
        if (root == NULL) return "";
        
        string bits = "";
        
        queue<TreeNode*> q;
        q.push(root);
        bits += to_string(root->val);
        bits += " ";
        while (!q.empty()) {
            TreeNode * u = q.front();
            q.pop();
            if (u->left != NULL) {
                q.push(u->left);
                bits += to_string(u->left->val);
                bits += " ";
            } else {
                bits += "#";
                bits += " ";
            }
            
            if (u->right != NULL) {
                q.push(u->right);
                bits += to_string(u->right->val);
                bits += " ";
            } else {
                bits += "#";
                bits += " ";
            }
        }
        int k = -1;
        for (int i = bits.size() - 1; i >= 0; --i) {
            if (bits[i] != '#' && bits[i] != ' ') {
                k = i + 1;
                break;
            }
        }
        bits.erase(k, bits.size());
        return bits;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(const string& data) {
        
        if (data.empty()) return NULL;
        
        stringstream ss(data);
        istream_iterator<string> begin(ss);
        istream_iterator<string> end;
        vector<string> D(begin, end);
        
        queue<TreeNode*> q;
        
        TreeNode * root = new TreeNode(stoi(D[0]));
        q.push(root);
        int i = 1;
        while (!q.empty()) {
            TreeNode * u = q.front();
            q.pop();
            
            if (i >= D.size()) break;
            
            if (D[i] != "#") {
                TreeNode * v = new TreeNode(stoi(D[i]));
                u->left = v;
                q.push(v);
            }
            if (i + 1 < D.size()) {
                if (D[i+1] != "#") {
                    TreeNode * v = new TreeNode(stoi(D[i+1]));
                    u->right = v;
                    q.push(v);
                }
            }
            i+=2;
        }
        return root;
    }
};
