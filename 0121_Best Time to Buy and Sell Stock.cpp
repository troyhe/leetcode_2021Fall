class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int lowestPrice = prices[0];
        for (int i = 1; i < prices.size(); i++){
            lowestPrice = min(lowestPrice, prices[i]);
            profit = max(profit, prices[i] - lowestPrice);
        }
        return profit;
    }
};
