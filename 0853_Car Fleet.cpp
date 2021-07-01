class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<int> idx(position.size());
        for (int i = 0; i < position.size(); i++) idx[i] = i;
        sort(idx.begin(), idx.end(), [&position, &speed](int idx1, int idx2){
            if (position[idx1] == position[idx2]) return speed[idx1] > speed[idx2];
            return position[idx1] > position[idx2];
        });
        int numCarFleet = 0;
        double curTime = 0;
        int curSpeed = INT_MAX;
        for (int i = 0; i < idx.size(); i++){
            double time = (target - position[idx[i]])/ (double) speed[idx[i]];
            if (time <= curTime && speed[idx[i]] >= curSpeed){
                
            } else {
                numCarFleet++;
                curTime = time;
                curSpeed = speed[idx[i]];
            }
        }
        return numCarFleet;
    }
};
