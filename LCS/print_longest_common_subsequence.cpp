// Print Longest Common Subsequence (LCS)
// DP + Backtracking
// dp[i][j] -> length of LCS of first i chars of text1 and first j chars of text2

// Time: O(n * m)
// Space: O(n * m)

string findLCS(int n, int m,string &s1, string &s2){
	
	vector<vector<int>> dp(n+1, vector<int>(m+1, 0 ));

    // build dp table
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			if(s1[i-1] == s2[j-1]){
				dp[i][j] = 1 + dp[i-1][j-1];
			}
			else{
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}

	// backtrack
	int i=n, j=m;
	string ans="";

	while(i>0 && j>0){
		if(s1[i-1] == s2[j-1]){
			ans.push_back(s1[i-1]);	// take char
			i--;
			j--;
		}
		else if(dp[i-1][j] > dp[i][j-1]){
			i--;	// move up
		}
		else{
			j--;	// move left
		}
	}

	reverse(ans.begin(), ans.end());	// fixing the order
	return ans;
}
