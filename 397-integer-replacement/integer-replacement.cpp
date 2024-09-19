class Solution {
public:
   unordered_map<int,int> dp;
    long long solve(long long n) {
        if (n == 1) {
            return 0;
        }
        if(dp.find(n)!=dp.end()){
            return dp[n];
        }
        if (n % 2 == 0) {
           return dp[n]= 1 + solve(n / 2);  
        } else {
           
            return dp[n]=1 + min(solve(n + 1), solve(n - 1));
        }
    }

    int integerReplacement(int n) {
        return solve(static_cast<long long>(n));  
    }
};
