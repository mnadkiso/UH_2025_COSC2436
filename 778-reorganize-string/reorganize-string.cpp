class Solution {
public:
    string reorganizeString(string s) {
        int cnt[26] = {};
        for (char c : s) cnt[c - 'a']++;
        priority_queue<pair<int, char>> pq;
        for (int i = 0; i < 26; i++)
            if (cnt[i]) pq.push({cnt[i], 'a' + i});
        string res;
        while (pq.size() > 1) {
            auto [c1, ch1] = pq.top(); pq.pop();
            auto [c2, ch2] = pq.top(); pq.pop();
            res += ch1;
            res += ch2;
            if (--c1) pq.push({c1, ch1});
            if (--c2) pq.push({c2, ch2});
        }
        if (!pq.empty()) {
            if (pq.top().first > 1) return "";
            res += pq.top().second;
        }
        return res;
    }
};