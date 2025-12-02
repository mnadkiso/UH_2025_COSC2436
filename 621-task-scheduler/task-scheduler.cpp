class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int cnt[26] = {};
        int maxFreq = 0, maxCount = 0;
        for (char c : tasks) {
            cnt[c - 'A']++;
            if (cnt[c - 'A'] > maxFreq) {
                maxFreq = cnt[c - 'A'];
                maxCount = 1;
            } else if (cnt[c - 'A'] == maxFreq) {
                maxCount++;
            }
        }
        return max((int)tasks.size(), (maxFreq - 1) * (n + 1) + maxCount);
    }
};