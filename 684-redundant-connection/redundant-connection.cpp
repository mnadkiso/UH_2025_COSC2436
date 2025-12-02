class Solution {
    int parent[1001];
    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        for (int i = 1; i <= 1000; i++) parent[i] = i;
        for (auto& e : edges) {
            int a = find(e[0]), b = find(e[1]);
            if (a == b) return e;
            parent[a] = b;
        }
        return {};
    }
};