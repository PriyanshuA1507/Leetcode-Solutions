class Solution {
public:
    long long solve(long long n) {
        if (n == 1) {
            return 0;
        }
        if (n % 2 == 0) {
            return 1 + solve(n / 2);  
        } else {
           
            return 1 + min(solve(n + 1), solve(n - 1));
        }
    }

    int integerReplacement(int n) {
        return solve(static_cast<long long>(n));  
    }
};
