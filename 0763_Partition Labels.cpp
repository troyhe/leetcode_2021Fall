class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> lastIdx;
        for (int i = 0; i < s.length(); i++){
            lastIdx[s[i]] = i;
        }
        priority_queue<int, vector<int>, greater<int>> pq;
        vector<int> ans;
        int lastPartition = -1;
        for (int i = 0; i < s.length(); i++){
            pq.push(lastIdx[s[i]]);
            while (!pq.empty() && pq.top() <= i){
                pq.pop();
            }
            if (pq.empty()){
                ans.push_back(i - lastPartition);
                lastPartition = i;
            }
        }
        return ans;
        
    }
};
