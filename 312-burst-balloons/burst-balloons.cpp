class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        
        // Add virtual balloons with value 1 at both ends
        vector<int> balloons(n + 2);
        balloons[0] = 1;
        balloons[n + 1] = 1;
        for (int i = 0; i < n; i++) {
            balloons[i + 1] = nums[i];
        }
        
        // dp[left][right] = max coins we can get by bursting balloons 
        // in the open interval (left, right)
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        
        // len is the length of the interval
        for (int len = 2; len <= n + 1; len++) {
            // left is the left boundary
            for (int left = 0; left + len <= n + 1; left++) {
                int right = left + len;
                
                // Try bursting each balloon k as the LAST one in (left, right)
                for (int k = left + 1; k < right; k++) {
                    // Coins gained by bursting k last:
                    // balloons[left] * balloons[k] * balloons[right]
                    // Plus coins from left subproblem + right subproblem
                    int coins = balloons[left] * balloons[k] * balloons[right];
                    coins += dp[left][k] + dp[k][right];
                    
                    dp[left][right] = max(dp[left][right], coins);
                }
            }
        }
        
        return dp[0][n + 1];
    }
};