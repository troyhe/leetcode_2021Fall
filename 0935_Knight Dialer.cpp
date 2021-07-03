class Solution {
public:
    int knightDialer(int n) {
        vector<vector<int>> dp(2, vector<int>(10, 1));
        int mod = 1e9 + 7;
        for (int i = 1; i < n; i++){
            dp[1][0] = (dp[0][4] + dp[0][6]) % mod;
            dp[1][1] = (dp[0][6] + dp[0][8]) % mod;
            dp[1][2] = (dp[0][7] + dp[0][9]) % mod;
            dp[1][3] = (dp[0][4] + dp[0][8]) % mod;
            dp[1][4] = ((dp[0][0] + dp[0][3]) % mod + dp[0][9]) % mod;
            dp[1][5] = 0;
            dp[1][6] = ((dp[0][0] + dp[0][1]) % mod + dp[0][7]) % mod;
            dp[1][7] = (dp[0][2] + dp[0][6]) % mod;
            dp[1][8] = (dp[0][1] + dp[0][3]) % mod;
            dp[1][9] = (dp[0][2] + dp[0][4]) % mod;
            dp[0] = dp[1];
        }
        int sum = 0;
        for (int i = 0; i < 10; i++){
            sum = (sum + dp[0][i]) % mod;
        }
        return sum;
    }
};
