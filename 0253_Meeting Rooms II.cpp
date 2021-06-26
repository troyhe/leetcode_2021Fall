class Solution {
    struct comp{
        bool operator()(const vector<int>& m1, const vector<int>& m2){
            return m1[1] > m2[1];
        }
    };
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        priority_queue<vector<int>, vector<vector<int>>, comp> rooms;
        for (int i = 0; i < intervals.size(); i++){
            if (!rooms.empty() && intervals[i][0] >= rooms.top()[1]){
                vector<int> emptyRoom = rooms.top();
                rooms.pop();
                emptyRoom[1] = intervals[i][1];
                rooms.push(emptyRoom);
            } else {
                rooms.push(intervals[i]);
            }
        }
        return rooms.size();
    }
};
