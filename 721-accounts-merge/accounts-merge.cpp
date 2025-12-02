class Solution {
    unordered_map<string, string> parent;
    string find(string x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, string> owner;
        for (auto& acc : accounts) {
            for (int i = 1; i < acc.size(); i++) {
                parent[acc[i]] = acc[i];
                owner[acc[i]] = acc[0];
            }
        }
        for (auto& acc : accounts) {
            string root = find(acc[1]);
            for (int i = 2; i < acc.size(); i++)
                parent[find(acc[i])] = root;
        }
        unordered_map<string, set<string>> merged;
        for (auto& acc : accounts)
            for (int i = 1; i < acc.size(); i++)
                merged[find(acc[i])].insert(acc[i]);
        vector<vector<string>> res;
        for (auto& [root, emails] : merged) {
            vector<string> acc(emails.begin(), emails.end());
            acc.insert(acc.begin(), owner[root]);
            res.push_back(acc);
        }
        return res;
    }
};