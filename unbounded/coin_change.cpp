// Coin Change
// Unbounded Knapsack (min coins)
// dp[i][j] -> min coins to make amount j using first i coins

// Time: O(n * amount)
// Space: O(n * amount)

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();

        int dp[n+1][amount+1];

        // amount = 0 -> 0 coins needed
        for(int i=0; i<=n; i++){
            dp[i][0]=0;
        }

        // no coins -> impossible to form amount
        for(int j=1; j<=amount; j++){
            dp[0][j]= INT_MAX-1;    // use large value instead of INT_MAX  to avoid overflow
        }

        // handling first coin separately
        for(int j=1; j<=amount; j++){
            if(j%coins[0]==0){
                dp[1][j]= j/coins[0];   // can be formed using only first coin
            }
            else{
                dp[1][j]= INT_MAX-1;    // not possible
            }
        }

        // then fill DP table
        for(int i=2; i<=n; i++){
            for(int j=1; j<=amount; j++){
                if(coins[i-1]<=j){
                    dp[i][j]=min(
                        dp[i-1][j], // skip
                        1+dp[i][j-coins[i-1]]   // take
                    );
                }
                else{
                    dp[i][j]=dp[i-1][j];    // can't take
                }
            }
        }

        // if still large then not possible
        if(dp[n][amount]==INT_MAX-1){
            return -1;
        }

        return dp[n][amount];
    }
};
