class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    string word;  // Store the complete word at the end node
    
    TrieNode() : word("") {}
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        // Build Trie from words
        TrieNode* root = buildTrie(words);
        
        vector<string> result;
        int m = board.size();
        int n = board[0].size();
        
        // Start DFS from each cell
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dfs(board, i, j, root, result);
            }
        }
        
        return result;
    }
    
private:
    TrieNode* buildTrie(vector<string>& words) {
        TrieNode* root = new TrieNode();
        
        for (const string& word : words) {
            TrieNode* node = root;
            for (char c : word) {
                if (node->children.find(c) == node->children.end()) {
                    node->children[c] = new TrieNode();
                }
                node = node->children[c];
            }
            node->word = word;  // Mark end of word
        }
        
        return root;
    }
    
    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* node, vector<string>& result) {
        int m = board.size();
        int n = board[0].size();
        
        // Boundary check
        if (i < 0 || i >= m || j < 0 || j >= n) {
            return;
        }
        
        char c = board[i][j];
        
        // Already visited or character not in Trie
        if (c == '#' || node->children.find(c) == node->children.end()) {
            return;
        }
        
        node = node->children[c];
        
        // Found a word
        if (!node->word.empty()) {
            result.push_back(node->word);
            node->word = "";  // Avoid duplicates
        }
        
        // Mark as visited
        board[i][j] = '#';
        
        // Explore all 4 directions
        dfs(board, i + 1, j, node, result);
        dfs(board, i - 1, j, node, result);
        dfs(board, i, j + 1, node, result);
        dfs(board, i, j - 1, node, result);
        
        // Backtrack: restore the cell
        board[i][j] = c;
    }
};