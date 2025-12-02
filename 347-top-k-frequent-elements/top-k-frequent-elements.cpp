class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        for (int n : nums) cnt[n]++;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        for (auto& [num, freq] : cnt) {
            pq.push({freq, num});
            if (pq.size() > k) pq.pop();
        }
        vector<int> res;
        while (!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};