// Longest Palindromic Subsequence
// Idea: LPS = LCS(original string, reversed string)

// Time: O(n * n), Space: O(n * n)

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string rev = s;
        reverse(s.begin(),s.end());

        int n=s.length();
        int m=rev.length();

        vector<vector<int>> dp(n+1, vector<int>(m+1,0));

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(s[i-1]==rev[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        return dp[n][m];
    }
};
