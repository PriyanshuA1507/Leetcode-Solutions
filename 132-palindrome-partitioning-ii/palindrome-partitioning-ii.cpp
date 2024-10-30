class Solution {
public:
    bool check(string& s,int start, int end) {
        bool a = true;
        int start1 = start, end1 = end;
        while (start1 < end1) {
            if (s[start1] != s[end1]) {
                a = false;
                break;
            }
            start1++;
            end1--;
        }
        return a; 
    }

    int solve(string& s, int start, int end,vector<vector<int>>& dp) {
        if (start >= end ||  check(s, start, end)) {
            return 0;
        }
        if(dp[start][end]!=-1){
            return dp[start][end];
        }
        int ans = 1e9;
        for (int k = start ; k <end; k++) {
            if (check(s,start,k)) {
                ans = min(ans, 1 + solve(s,k+1,end,dp));
            }
        }
        return dp[start][end]=ans;
    }

    int minCut(string s) {
        int n = s.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solve(s, 0, n - 1,dp);
    }
};
