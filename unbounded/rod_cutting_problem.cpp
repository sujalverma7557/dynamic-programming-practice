// Rod Cutting (DP)
// Basically same as unbounded knapsack

// dp[i][j] -> max profit using lengths 1..i to make rod of length j

class Solution {
  public:
    int cutRod(vector<int> &price) {
        int n = price.size();
        
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                
                if(i <= j) {
                    // either we take this length or skip
                    dp[i][j] = max(
                        price[i-1] + dp[i][j - i], //take (can reuse)
                        dp[i-1][j] // skip
                    );
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        return dp[n][n];
    }
};
