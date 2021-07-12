class Solution {
public:
    int minAddToMakeValid(string s) {
        int num = 0;
        stack<int> openParetheses;
        for (int i = 0; i < s.length(); i++){
            if (s[i] == '('){
                openParetheses.push(i);
            } else if (s[i] == ')'){
                if (!openParetheses.empty()){
                    openParetheses.pop();
                } else {
                    num += 1;
                }
            }
        }
        return num + openParetheses.size();
    }
};
