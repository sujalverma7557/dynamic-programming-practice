// Matrix Chain Multiplication (Memoization)
// Idea: Try all partition points (k) and take minimum cost,
//       cost = left + right + multiplication cost of current split

// Time: O(n^3), Space: O(n^2) + recursion stack

class Solution {
  public:
    int dp[101][101];
    
    int solve(vector<int> &arr, int i, int j){
        if(i>=j){
            return 0;
        }
        
        // Then we check if already computed
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        int mn=INT_MAX;
        
        //Now try all the partitions
        for(int k=i; k<=j-1; k++){
            int temp= solve(arr,i,k) + solve(arr,k+1,j) + arr[i-1]*arr[k]*arr[j];
            mn=min(mn,temp);
        }
        
        return dp[i][j]=mn;
    }
  
  
    int matrixMultiplication(vector<int> &arr) {
        int n=arr.size();
        
        memset(dp,-1, sizeof(dp));
        
        return solve(arr,1,n-1);
    }
};
