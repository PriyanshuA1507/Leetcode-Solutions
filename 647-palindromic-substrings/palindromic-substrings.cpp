class Solution {
public:
    bool check(string &s, int start, int end,vector<int>& dp) {
        while (start <= end) {
            if (s[start] != s[end]) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }

    int solve(string &s, int index,vector<int>& dp) {
        if (index >= s.size()) {
            return 0;
        }
        if(dp[index]!=-1){
            return dp[index];
        }

        int count = 0;
        for (int i = index; i < s.size(); i++) {
            if (check(s, index, i,dp)) {
                count++; 
            }
        }
        return dp[index]=count + solve(s, index + 1,dp); 
    }

    int countSubstrings(string s) {
        int n = s.size();
        vector<int> dp(n+1,-1);
        return solve(s, 0,dp);
    }
};
