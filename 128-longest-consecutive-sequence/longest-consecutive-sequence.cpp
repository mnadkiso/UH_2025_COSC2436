class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int res = 0;
        for (int n : st) {
            if (!st.count(n - 1)) {
                int len = 1;
                while (st.count(n + len)) len++;
                res = max(res, len);
            }
        }
        return res;
    }
};