class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // There is an important condition that the input array is sorted.
        // We should make use of that.
        
        // Initialization:
        vector<int> ans(2,0);
        int left = 0;
        int right = numbers.size() - 1;
        while (left < right){
            if (numbers[left] + numbers[right] == target){
                // Found!
                // Pay attention to whether it is 1-index or 0-index
                ans[0] = left + 1;
                ans[1] = right + 1;
                break;
            } else if (numbers[left] + numbers[right] > target){
                right--;
            } else {
                left++;
            }
        }
        return ans;
        
    }
};
