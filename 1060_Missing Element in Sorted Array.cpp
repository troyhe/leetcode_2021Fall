class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        int len = nums.size();
        int emptyPos = nums[len - 1] - nums[0] - len + 1;
        if (emptyPos < k) return nums[len-1] + k - emptyPos;
        // if (k < num[0]) return k;
        // Do binary Search to find idx that #empty postion between nums[0] and nums[idx] < k 
        // While nums[0] and nums[idx+1] >= k;
        
        int left = 0;
        int right = len - 2;
        while (left <= right){
            int mid = left + (right - left)/2;
            int emptyPos1 = nums[mid] - nums[0] - mid;
            int emptyPos2 = nums[mid+1] - nums[0] - mid - 1;
            if (emptyPos1 >= k){
                right = mid - 1;
            } else if (emptyPos2 < k){
                left = mid + 1;
            } else {
                return nums[mid] + k - emptyPos1;
            }
        }
        return 0;
    }
};
