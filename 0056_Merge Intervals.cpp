class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        if (intervals.size() == 0) return ans;
        // Sort the input
        sort(intervals.begin(), intervals.end());
        // Deal with Overlap
        ans.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++){
            if (intervals[i][0] <= ans[ans.size() - 1][1]){
                ans[ans.size() - 1][1] = max(ans[ans.size() - 1][1], intervals[i][1]);
            } else {
                ans.push_back(intervals[i]);
            }
        }
        // Output
        return ans;
    }
};
