// Longest Common Subsequence (LCS)
// Classic DP problem (string matching)
// dp[i][j] -> length of LCS of first i chars of text1 and first j chars of text2

// Time: O(n * m)
// Space: O(n * m)

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // filling DP table
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                
                if(text1[i-1] == text2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];  // match
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);  // skip
                }
            }
        }

        return dp[n][m];
    }
};
