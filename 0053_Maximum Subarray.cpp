class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        int maxCur = 0; // The maximum value of the subarray ends at current postion;
        for (int i = 0; i < nums.size(); i++){
            maxCur = max(maxCur, 0) + nums[i];
            maxSum = max(maxSum, maxCur);
        }
        return maxSum;
    }
};
