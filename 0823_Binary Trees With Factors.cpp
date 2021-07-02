class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        unordered_map<int, int> factorIdx;
        vector<long> dp(arr.size(), 1);
        int sum = 0;
        int mod = 1e9 + 7;
        for (int i = 0; i < arr.size(); i++){
            factorIdx[arr[i]] = i;
            for (int j = 0; j < i; j++){
                if (arr[i] % arr[j] == 0 && factorIdx.find(arr[i]/arr[j]) != factorIdx.end()){
                    dp[i] = (dp[i] + dp[j] * dp[factorIdx[arr[i]/arr[j]]]) % mod;
                }
                                        
            }
            sum = (sum + dp[i]) % mod;
        }
        return sum;
    }
};
