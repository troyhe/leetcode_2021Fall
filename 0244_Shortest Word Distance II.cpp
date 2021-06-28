class WordDistance {
    unordered_map<string, vector<int>> dic;
public:
    WordDistance(vector<string>& wordsDict) {
        for (int i = 0 ; i < wordsDict.size(); i++){
            dic[wordsDict[i]].push_back(i);
        }
    }
    
    int shortest(string word1, string word2) {
        vector<int>& indices1 = dic[word1];
        vector<int>& indices2 = dic[word2];
        int minDis = INT_MAX;
        for (int i = 0, j = 0; i < indices1.size() && j < indices2.size();
            ){
            minDis = min(abs(indices1[i] - indices2[j]), minDis);
            if (indices1[i] < indices2[j]) i++;
            else j++;
        }
        return minDis;
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(wordsDict);
 * int param_1 = obj->shortest(word1,word2);
 */
