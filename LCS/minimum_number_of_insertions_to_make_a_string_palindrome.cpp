// Minimum Insertions to Make String Palindrome
// Idea: Insertions = n - LPS (longest palindromic subsequence)

// Time: O(n * n), Space: O(n * n)

class Solution {
public:
    int minInsertions(string s) {
        int n=s.length();

        string rev=s;
        reverse(s.begin(), s.end());

        vector<vector<int>> dp(n+1, vector<int>(n+1,0));

        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(s[i-1]==rev[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        int lcs=dp[n][n];

        return n-lcs;
    }
};
