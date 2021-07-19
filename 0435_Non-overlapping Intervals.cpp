class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.size() <= 1) return 0;
        sort(intervals.begin(), intervals.end());
        int before = 0;
        int numRemoved = 0;
        for (int i = 1; i < intervals.size(); i++){
            if (intervals[before][1] > intervals[i][0]){
                if (intervals[before][1] > intervals[i][1]){
                    before = i;
                }
                numRemoved++;
            } else {
                before = i;
            }
        }
        return numRemoved;
        
    }
};
