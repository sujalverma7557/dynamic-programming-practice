// Palindrome Partitioning II (Minimum Cuts)
// Idea: Precompute all palindromic substrings,
//       then dp[i] = min cuts needed for prefix [0..i] by trying all valid partitions

// Time: O(n^2), Space: O(n^2)

class Solution {
public:
    int minCut(string s) {
        int n = s.size();

        vector<vector<bool>> isPal(n, vector<bool>(n, false));

        // every single char is palindrome
        for (int i = 0; i < n; i++){
            isPal[i][i] = true;
        }

        // fill palindrome table
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;

                if (len == 2)
                    isPal[i][j] = (s[i] == s[j]); // two chars
                else
                    isPal[i][j] = (s[i] == s[j] && isPal[i+1][j-1]); // expand
            }
        }

        vector<int> dp(n, 0);

        // dp[i] -> min cuts for s[0..i]
        for (int i = 0; i < n; i++) {
            if (isPal[0][i]) {
                dp[i] = 0; // whole substring is palindrome
            } else {
                dp[i] = INT_MAX;

                // try all partitions
                for (int j = 0; j < i; j++) {
                    if (isPal[j+1][i]) {
                        dp[i] = min(dp[i], dp[j] + 1); // cut at j
                    }
                }
            }
        }

        return dp[n-1];
    }
};
