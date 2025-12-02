class Solution {
public:
    string longestWord(vector<string>& words) {
        unordered_set<string> st(words.begin(), words.end());
        string res = "";
        for (const string& w : words) {
            bool valid = true;
            for (int i = 1; i < w.size(); i++) {
                if (!st.count(w.substr(0, i))) {
                    valid = false;
                    break;
                }
            }
            if (valid && (w.size() > res.size() || (w.size() == res.size() && w < res)))
                res = w;
        }
        return res;
    }
};