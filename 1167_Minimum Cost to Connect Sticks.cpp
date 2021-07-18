class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int cost = 0;
        for (int i = 0; i < sticks.size(); i++){
            pq.push(sticks[i]);
        }
        while (pq.size() > 1){
            int s1 = pq.top();
            pq.pop();
            int s2 = pq.top();
            pq.pop();
            cost += s1 + s2;
            pq.push(s1 + s2);
        }
        return cost;
    }
};
