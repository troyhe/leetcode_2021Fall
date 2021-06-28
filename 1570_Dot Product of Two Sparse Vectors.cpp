class SparseVector {
    vector<pair<int, int>> digits;
public:
    SparseVector(vector<int> &nums) {
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] != 0) digits.push_back({i, nums[i]});
        }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int i = 0, j = 0;
        int sum = 0;
        while (i < digits.size() && j < vec.digits.size()){
            if (digits[i].first == vec.digits[j].first){
                sum += digits[i].second * vec.digits[j].second;
                i++;
                j++;
            } else if (digits[i].first > vec.digits[j].first){
                j++;
            } else {
                i++;
            }
        }
        return sum;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);
