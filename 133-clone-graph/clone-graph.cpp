class Solution {
    unordered_map<Node*, Node*> mp;
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        if (mp.count(node)) return mp[node];
        mp[node] = new Node(node->val);
        for (auto n : node->neighbors)
            mp[node]->neighbors.push_back(cloneGraph(n));
        return mp[node];
    }
};