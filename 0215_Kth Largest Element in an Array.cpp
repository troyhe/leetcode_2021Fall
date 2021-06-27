class Solution {
    int partition(vector<int>& nums, int left, int right){
        int pivot = --right;
        while (true){
            while (nums[left] < nums[pivot]) left++;
            while (left < right && nums[right-1] >= nums[pivot]) right--;
            if (left >= right) break;
            swap(nums[left], nums[right-1]);
        }
        swap(nums[left], nums[pivot]);
        return left;
    }
    
    int quickSelect(vector<int>& nums, int left, int right, int k){
        if (left >= right + 1) return nums[k];
        int pivot = partition(nums, left, right);
        if (pivot == k) return nums[k];
        if (pivot < k) return quickSelect(nums, pivot + 1, right, k);
        return quickSelect(nums, left, pivot, k);
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        return quickSelect(nums, 0, nums.size(), nums.size() - k);
    }
};
