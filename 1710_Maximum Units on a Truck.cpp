class Solution {
    struct comp{
        bool operator()(const vector<int>& vec1, const vector<int>& vec2){
            return vec1[1] > vec2[1];
        }
    };
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), comp());
        int sum = 0;
        for (int i = 0; i < boxTypes.size(); i++){
            if (boxTypes[i][0] < truckSize){
                sum += boxTypes[i][0]*boxTypes[i][1];
                truckSize -= boxTypes[i][0];
            } else {
                sum += truckSize*boxTypes[i][1];
                truckSize = 0;
                break;
            }
        }
        return sum;
    }
};
