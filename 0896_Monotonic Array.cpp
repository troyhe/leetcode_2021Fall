class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int sign = 0;
        for (int i = 0; i < nums.size() - 1; i++){
            if (nums[i] < nums[i+1]){
                if (sign > 0) return false;
                sign = -1;
            } else if (nums[i] > nums[i+1]){
                if (sign < 0) return false;
                sign = 1;
            }
        }
        return true;
    }
};
