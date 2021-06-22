class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans(2, 0);
        // hash map for <value, index>
        unordered_map<int, int> dic;
        for (int i = 0; i < nums.size(); i++){
            if (dic.find(target - nums[i]) != dic.end()){
                ans[0] = dic[target - nums[i]];
                ans[1] = i;
                break;
            } else {
                dic[nums[i]] = i;
            }
        }
        return ans;
    }
};
