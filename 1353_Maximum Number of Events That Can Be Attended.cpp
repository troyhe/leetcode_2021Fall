class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        int eventAttended = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        int idx = 0;
        for (int i = events[0][0]; i <= 100000; i++){
            while (!pq.empty() && pq.top() < i) pq.pop();
            while (idx < events.size() && events[idx][0] <= i){
                pq.push(events[idx][1]);
                idx++;
            }
            if (!pq.empty() && pq.top() >= i){
                eventAttended += 1;
                pq.pop();
            }
            if (idx == events.size() && pq.empty()) break;
        }
        return eventAttended; 
    }
};
