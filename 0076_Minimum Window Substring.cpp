class Solution {
public:
    string minWindow(string s, string t) {
        // Extract the information from string t
        unordered_map<char, int> pattern;
        int requirements = 0;
        for (int i = 0; i < t.length(); i++){
            if (pattern[t[i]] == 0) requirements++;
            pattern[t[i]]++;
        }
        // Define the window as a close interval
        // [left, right]
        int left = 0;
        int right = 0;
        unordered_map<char, int> window;
        int satisfying = 0;
        int minLength = INT_MAX;
        string ans = "";
        while (left <= right && right < s.length()){
            // a new character added
            window[s[right]]++;
            if (pattern[s[right]] > 0 && window[s[right]] == pattern[s[right]]) satisfying++;
            while (satisfying == requirements){
                if (right - left + 1 < minLength){
                    minLength = right - left + 1;
                    ans = s.substr(left, minLength);
                }
                // a character is deleted
                window[s[left]]--;
                if (pattern[s[left]] > 0 && window[s[left]] < pattern[s[left]]) satisfying--;
                left++;
            }
            right++;
        }
        return ans;
        
    }
};
