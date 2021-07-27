class Solution {
public:
    double myPow(double x, int n) {
        // We only consider n >= 0 first
        if (n == 0) return 1;
        if (n > 0){
            double half = myPow(x, n/2);
            return half*half*(n%2?x:1);
        }
        if (n < 0){
            double half = myPow(x, -(n/2));
            return 1/(half*half*(n%2?x:1));
        }
        return 0;
    }
};
