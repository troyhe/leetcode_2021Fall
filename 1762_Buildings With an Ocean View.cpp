class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        stack<int> buildings;
        int maxHeight = INT_MIN;
        for (int i = heights.size() - 1; i >= 0; i--){
            if (heights[i] > maxHeight){
                buildings.push(i);
                maxHeight = heights[i];
            }
        }
        vector<int> ans;
        while (!buildings.empty()){
            ans.push_back(buildings.top());
            buildings.pop();
        }
        return ans;
    }
};
