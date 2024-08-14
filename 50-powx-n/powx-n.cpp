class Solution {
public:
    double myPow(double x, long long n) {
       // Base cases
        if (n == 0) {
            return 1;
        }
        if (x == 0) {
            return 0;
        }

        // Handle negative power
        if (n < 0) {
            x = 1 / x;
            n = -n;
        }

        // Recursive call with optimization (divide and conquer)
        double half = myPow(x, n / 2);

        if (n % 2 == 0) {
            return half * half;  // Even exponent
        } else {
            return half * half * x;  // Odd exponent
        }
    }
};