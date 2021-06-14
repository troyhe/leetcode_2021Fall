class Solution {
public:
    bool isValid(string s) {
        stack<char> parethesis;
        for (char c: s){
            if (c == '(' || c == '[' || c == '{'){
                parethesis.push(c);
            } else {
                if (parethesis.empty()) return false;
                if (c == ')'){
                    if (parethesis.top() == '('){
                        parethesis.pop();
                    } else return false;
                } else if (c == ']'){
                    if (parethesis.top() == '['){
                        parethesis.pop();
                    } else return false;
                } else if (c == '}'){
                    if (parethesis.top() == '{'){
                        parethesis.pop();
                    } else return false;
                }
            }
        }
        if (parethesis.empty()) return true;
        return false;
    }
};
