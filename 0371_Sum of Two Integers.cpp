class Solution {
public:
    int getSum(int a, int b) {
        int digit = a ^ b;
        int carry = a & b;
        if (carry < 0) carry = carry & (0x7FFFFFFF);
        if (!carry || carry == INT_MIN) return digit;
        return getSum(digit, carry << 1);
    }
};
