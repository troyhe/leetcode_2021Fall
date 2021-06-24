class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        // Intuition to use sliding window
        
        // <character, the rightmost index it appears in the window;
        unordered_map<char, int> dic;
        
        // The window will be a close interval [left, i]
        int left = 0;
        int maxLength = 0;
        for (int i = 0; i < s.length(); i++){
            if (dic.find(s[i]) == dic.end() && dic.size() == 2){
                int minIdx = i;
                char c = s[i];
                // find the element with leftest rightmost index and delete it
                for (auto it: dic){
                    if (it.second < minIdx){
                        minIdx = it.second;
                        c = it.first;
                    }
                }
                left = minIdx + 1;
                dic.erase(c);
            }
            dic[s[i]] = i;
            maxLength = max(maxLength, i - left + 1);
        
        }
        return maxLength;
    }
};
