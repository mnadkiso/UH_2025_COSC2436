class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        
        // dp[i][j] represents the minimum edit distance between
        // word1[0...i-1] and word2[0...j-1]
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        // Base cases: converting from/to empty string
        for (int i = 0; i <= m; i++) {
            dp[i][0] = i;  // Delete all characters from word1
        }
        for (int j = 0; j <= n; j++) {
            dp[0][j] = j;  // Insert all characters from word2
        }
        
        // Fill the dp table
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    // Characters match, no operation needed
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    // Characters don't match, try all three operations
                    dp[i][j] = 1 + min({
                        dp[i - 1][j],      // Delete from word1
                        dp[i][j - 1],      // Insert into word1
                        dp[i - 1][j - 1]   // Replace in word1
                    });
                }
            }
        }
        
        return dp[m][n];
    }
};