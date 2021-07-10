class Solution {
    string digitToWord(int num){
        // 0 <= num <= 9
        switch (num){
            case 0:
                return "Zero";
            case 1:
                return "One";
            case 2:
                return "Two";
            case 3:
                return "Three";
            case 4:
                return "Four";
            case 5:
                return "Five";
            case 6:
                return "Six";
            case 7:
                return "Seven";
            case 8:
                return "Eight";
            case 9:
                return "Nine";
        }
        return "";       
    }
    string tensToWord(int num){
        switch (num / 10){
            case 0:
                return "Zero";
            case 1:
                return "One";
            case 2:
                return "Twenty";
            case 3:
                return "Thirty";
            case 4:
                return "Forty";
            case 5:
                return "Fifty";
            case 6:
                return "Sixty";
            case 7:
                return "Seventy";
            case 8:
                return "Eighty";
            case 9:
                return "Ninety";
        }
        return ""; 
    }
    string numberToWord10(int num){
        // 0 < num <= 99
        if (num < 10) return digitToWord(num);
        if (num < 20){
            switch (num){
                case 10:
                    return "Ten";
                case 11:
                    return "Eleven";
                case 12:
                    return "Twelve";
                case 13:
                    return "Thirteen";
                case 14:
                    return "Fourteen";
                case 15:
                    return "Fifteen";
                case 16:
                    return "Sixteen";
                case 17:
                    return "Seventeen";
                case 18:
                    return "Eighteen";
                case 19:
                    return "Nineteen";
            }
        }
        if (num % 10 == 0) return tensToWord(num);
        string ans = tensToWord(num) + ' ' + digitToWord(num % 10);
        return ans;
    }
    string numberToWord100(int num){
        // 0 < num <= 999
        string ans = "";
        if (num >= 100){
            ans += digitToWord(num / 100) + " Hundred";
            num = num % 100;
            if (num == 0) return ans;
            ans += " ";
        }
        ans += numberToWord10(num);
        return ans;
    }
public:
    string numberToWords(int num) {
        string ans = "";
        if (num == 0) return "Zero";
        int billions = num / 1000000000;
        num = num % 1000000000;
        int millions = num / 1000000;
        num = num % 1000000;
        int thousands = num / 1000;
        num = num % 1000;
        if (billions > 0) ans += numberToWord100(billions) + " Billion";
        if (millions > 0){
            if (ans.length() > 0) ans += " " + numberToWord100(millions) + " Million";
            else ans += numberToWord100(millions) + " Million";
        }
        if (thousands > 0){
            if (ans.length() > 0) ans += " " + numberToWord100(thousands) + " Thousand";
            else ans += numberToWord100(thousands) + " Thousand";
        }
        if (num == 0) return ans;
        if (ans.length() > 0) ans += " " + numberToWord100(num);
        else ans += numberToWord100(num);
        return ans;
        
    }
};
