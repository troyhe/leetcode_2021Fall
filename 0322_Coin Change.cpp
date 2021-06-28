class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        vector<int> coinsNeeded(amount + 1, INT_MAX);
        coinsNeeded[0] = 0;
        for (int i = 1; i <= amount; i++){
            for (int j = 0; j < coins.size() && coins[j] <= i; j++){
                if (coinsNeeded[i - coins[j]] != INT_MAX){
                    coinsNeeded[i] = min(coinsNeeded[i], coinsNeeded[i - coins[j]]+1);
                } 
            }
        }
        return (coinsNeeded[amount] == INT_MAX)?-1:coinsNeeded[amount];
    }
};
