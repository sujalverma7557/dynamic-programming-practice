// Longest Common Substring
// DP (variation of LCS in which continuous match is required)
// dp[i][j] -> length of longest common substring ending at i (text1) and j (text2)

// Time: O(n * m)
// Space: O(n * m)

class Solution {
  public:
    int longCommSubstr(string& s1, string& s2) {
        int n=s1.size();
        int m=s2.size();
        int ans=0;
        
        vector<vector<int>> dp(n+1, vector<int>(m+1,0));
        
        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];    // extend substring
                }
                else{
                    dp[i][j] = 0;   // break substring
                }
            }
        }
        
        return ans;
    }
};
