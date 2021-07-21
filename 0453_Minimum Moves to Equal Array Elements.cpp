class Solution {
public:
    int minMoves(vector<int>& nums) {
        // find the smallest element
        int minimun = nums[0];
        for (int i = 0; i < nums.size(); i++) minimun = min(minimun, nums[i]);
        int steps = 0;
        for (int i = 0; i < nums.size(); i++) steps += nums[i] - minimun;
        return steps;
    }
};
