class Solution {
public:
    int minCost(string s, vector<int>& cost) {
        int firstIdx = 0;
        int sum = 0;
        for (int i = 1; i < s.length(); i++){
            if (s[i] == s[firstIdx]){
                if (cost[i] <= cost[firstIdx]){
                    sum += cost[i];
                } else {
                    sum += cost[firstIdx];
                    firstIdx = i;
                }
            } else {
                firstIdx = i;
            }
        }
        return sum;
    }
};
