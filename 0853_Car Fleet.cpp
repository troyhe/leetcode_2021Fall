class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> cars(position.size());
        for (int i = 0; i < position.size(); i++){
            cars[i] = {position[i], speed[i]}; 
        }
        sort(cars.begin(), cars.end());
        int numCarFleet = 0;
        double curTime = 0;
        int curSpeed = INT_MAX;
        for (int i = (int) cars.size() - 1; i >= 0; i--){
            double time = (target - cars[i].first)/ (double)cars[i].second;
            if (time <= curTime && cars[i].second >= curSpeed){
                
                // curTime = time;
                // curSpeed = cars
            } else {
                numCarFleet++;
                curTime = time;
                curSpeed = cars[i].second;
            }
        }
        return numCarFleet;
    }
};
