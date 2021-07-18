class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0;
        int cows = 0;
        vector<int> secretNum(10, 0);
        vector<int> guessNum(10, 0);
        for (int i = 0; i < secret.size(); i++){
            if (secret[i] == guess[i]) bulls++;
            else {
                secretNum[secret[i] - '0']++;
                guessNum[guess[i] - '0']++;
            }
        }
        for (int i = 0; i < 10; i++){
            cows += min(secretNum[i], guessNum[i]);
        }
        return to_string(bulls) + 'A' + to_string(cows) + 'B';
    }
};
