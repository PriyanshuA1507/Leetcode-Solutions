class Solution {
public:
    long solve(vector<vector<int>>& questions, int index,vector<long long> &dp) {
        if (index >= questions.size()) {
            return 0;
        }
        if(dp[index]!=-1)
        return dp[index];

        long long nottake = solve(questions, index + 1,dp);

        long long take =  questions[index][0];
        if (index + questions[index][1] < questions.size() ) {  // Remove the semicolon
            take += solve(questions, index + questions[index][1]+1,dp);
        }

        return dp[index]=max(take, nottake);
    }

    long mostPoints(vector<vector<int>>& questions) {
        int n= questions.size();
       vector<long long> dp(n+1,-1);
        return solve(questions, 0,dp);
    }
};