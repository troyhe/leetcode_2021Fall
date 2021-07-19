class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int maxVal = nums[0];
        int minVal = nums[0];
        for (int i = 0; i < nums.size(); i++){
            maxVal = max(maxVal, nums[i]);
            minVal = min(minVal, nums[i]);
        }
        if (maxVal - minVal <= 2 *k) return 0;
        return maxVal - minVal - 2 * k;
    }
};
