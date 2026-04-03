// Coin Change II
// Unbounded Knapsack (count ways)
// dp[i][j] -> number of ways to make amount j using first i coins

// Time: O(n * amount)
// Space: O(n * amount)


class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();

        // Using unsigned long long to prevent the UBSan runtime error
        vector<vector<unsigned long long>> dp(n+1, vector<unsigned long long>(amount+1,0));

        // amount = 0 -> 1 way (take nothing)
        for(int i=0; i<=n; i++){
            dp[i][0]=1;
        }

        // filling DP table
        for(int i=1; i<=n; i++){
            for(int j=1; j<=amount; j++){
                if(coins[i-1]<=j){
                    dp[i][j]=dp[i-1][j] + dp[i][j-coins[i-1]];
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }

        return (int)dp[n][amount];
    }
};
