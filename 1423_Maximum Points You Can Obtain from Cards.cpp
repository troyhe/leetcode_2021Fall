class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int size = cardPoints.size();
        int sum = 0;
        for (int i = 0; i < k; i++) sum += cardPoints[size - k + i];
        int maxScore = sum;
        for (int i = 0; i < k; i++){
            sum += cardPoints[i];
            sum -= cardPoints[size - k + i];
            maxScore = max(maxScore, sum);
        }
        return maxScore;
    }
};
