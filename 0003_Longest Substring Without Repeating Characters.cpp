class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Intuition is to use sliding window. 
        
        // a map for the last index of a character 
        // <character, idx>
        unordered_map<char, int> dic;
        int minLength = 0;
        int left = 0; 
        // the begin index of a substring without repeating character ending at i
        for (int i = 0; i < s.length(); i++){
            if (dic.find(s[i]) != dic.end()){
                left = max(left, dic[s[i]] + 1);
            }
            minLength = max(minLength, i - left + 1);
            dic[s[i]] = i;
        }
        return minLength;
    }
};
