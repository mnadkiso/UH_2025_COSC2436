/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "[]";
        
        string result = "[";
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            
            if (node) {
                result += to_string(node->val) + ",";
                q.push(node->left);
                q.push(node->right);
            } else {
                result += "null,";
            }
        }
        
        // Remove trailing comma and add closing bracket
        if (result.back() == ',') {
            result.pop_back();
        }
        result += "]";
        
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "[]") return nullptr;
        
        // Remove brackets and parse values
        data = data.substr(1, data.length() - 2);
        vector<string> values = split(data, ',');
        
        if (values.empty() || values[0] == "null") return nullptr;
        
        TreeNode* root = new TreeNode(stoi(values[0]));
        queue<TreeNode*> q;
        q.push(root);
        
        int i = 1;
        while (!q.empty() && i < values.size()) {
            TreeNode* node = q.front();
            q.pop();
            
            // Process left child
            if (i < values.size() && values[i] != "null") {
                node->left = new TreeNode(stoi(values[i]));
                q.push(node->left);
            }
            i++;
            
            // Process right child
            if (i < values.size() && values[i] != "null") {
                node->right = new TreeNode(stoi(values[i]));
                q.push(node->right);
            }
            i++;
        }
        
        return root;
    }
    
private:
    vector<string> split(const string& s, char delimiter) {
        vector<string> tokens;
        string token;
        istringstream tokenStream(s);
        while (getline(tokenStream, token, delimiter)) {
            tokens.push_back(token);
        }
        return tokens;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));