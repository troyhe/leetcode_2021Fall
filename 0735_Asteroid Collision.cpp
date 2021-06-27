class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> results;
        deque<int> positives;
        for (int i = 0; i < asteroids.size(); i++){
            if (asteroids[i] > 0) positives.push_back(asteroids[i]);
            else {
                while (!positives.empty() && positives.back() < -asteroids[i]){
                    positives.pop_back();
                }
                if (positives.empty()) results.push_back(asteroids[i]);
                else if (positives.back() == -asteroids[i]) positives.pop_back();
            }
        }
        while (!positives.empty()){
            results.push_back(positives.front());
            positives.pop_front();
        }
        return results;
    }
};
