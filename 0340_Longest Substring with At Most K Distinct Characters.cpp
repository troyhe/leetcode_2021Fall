class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if (k == 0) return 0;
        // Intuition to use sliding window. 
        unordered_map<char, int> dic;
        int maxLen = 0;
        int left = 0;
        for (int i = 0; i < s.length(); i++){
            if (dic.find(s[i]) == dic.end() && dic.size() == k){
                // We would like to find the character with smallest corresponding value in the dic
                int minIdx = i;
                char c = s[i];
                for (auto it: dic){
                    if (it.second < minIdx){
                        c = it.first;
                        minIdx = it.second;
                    }
                }
                left = minIdx + 1;
                dic.erase(c);
            } 
            dic[s[i]] = i;
            maxLen = max(maxLen, i - left + 1);
        }
        return maxLen;
    }
};
