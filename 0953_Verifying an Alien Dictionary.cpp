class Solution {
    
    bool helper(const string& word1, const string& word2, unordered_map<char, int> &rank){
        for (int i = 0; i < word1.length(); i++){
            if (i >= word2.length()) return false;
            if (word1[i] == word2[i]) continue;
            // Comes word[i] != word2[i]
            if (rank[word1[i]] > rank[word2[i]]) return false;
            return true;
        }
        return true;
    }
public:
    
    // Intuition:
    // Step 1: Extract the order of the character with hashmap
    // Step 2: Compare every two adjacent words using the hashmap
    // Complexity: O(n) + O(m) where n = #words, m = #letters
    bool isAlienSorted(vector<string>& words, string order) {
        // Step 1:
        unordered_map<char, int> rank;
        for (int i = 0; i < order.length(); i++){
            rank[order[i]] = i;
        }
        for (int i = 0; i < words.size() - 1; i++){
            if (!helper(words[i], words[i+1], rank)) return false;
        }
        return true;
    }
};
