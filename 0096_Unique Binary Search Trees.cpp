class Solution {
public:
    int numTrees(int n) {
        // From last problem, we can get some inspirations. 
        // The number of stucturally unique BST with certain number of distinct values are the same, regardless of the specific values of the nodes.
        // We can get the formula for dp
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; i++){
            for (int j = 0; j < i; j++){
                dp[i] += dp[j]*dp[i-j-1];
            }
        }
        return dp[n];
    }
};
