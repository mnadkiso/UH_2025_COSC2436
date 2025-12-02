class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        vector<string> res;
        string mapping[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        backtrack(digits, mapping, 0, "", res);
        return res;
    }
    
    void backtrack(string& digits, string mapping[], int idx, string cur, vector<string>& res) {
        if (idx == digits.size()) {
            res.push_back(cur);
            return;
        }
        for (char c : mapping[digits[idx] - '0'])
            backtrack(digits, mapping, idx + 1, cur + c, res);
    }
};