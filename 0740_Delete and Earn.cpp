class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int, int> counts;
        for (int i = 0; i < nums.size(); i++){
            counts[nums[i]] += 1;
        }
        vector<vector<int>> numCount;
        for (auto it: counts){
            numCount.push_back({it.first, it.second});
        }
        sort(numCount.begin(), numCount.end());
        vector<int> dp(numCount.size()+1);
        dp[0] = 0;
        dp[1] = numCount[0][0] * numCount[0][1];
        for (int i = 1; i < numCount.size(); i++){
            if (numCount[i][0] - 1 == numCount[i-1][0]){
                dp[i+1] = max(dp[i], dp[i-1] + numCount[i][0] * numCount[i][1]);
            } else {
                dp[i+1] = dp[i] + numCount[i][0] * numCount[i][1];
            }
        }
        return dp[numCount.size()];                      
                              
    }
};
