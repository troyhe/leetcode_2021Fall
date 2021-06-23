class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // Initialization. 
        vector<vector<int>> ans;
        if (nums.size() < 3) return ans;
        
        
        sort(nums.begin(), nums.end());
        // fix one element and then find the other two
        for (int i = 0; i < nums.size() - 2; i++){
            // Remove duplicate
            if (i > 0 && nums[i] == nums[i-1]) continue;
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right){
                int sum = nums[i] + nums[left] + nums[right];
                if (sum > 0){
                    right--;
                } else if (sum < 0){
                    left++;
                } else {
                    vector<int> triplet(3, 0);
                    triplet[0] = nums[i];
                    triplet[1] = nums[left];
                    triplet[2] = nums[right];
                    ans.push_back(triplet);
                    while (left < right && nums[left] == nums[left+1]) left++;
                    left++;
                }
            }
            
        }
        return ans;
    }
};
