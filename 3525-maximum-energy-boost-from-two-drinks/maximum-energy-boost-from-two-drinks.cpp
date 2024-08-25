class Solution {
public:
    long long solve(vector<int>& e1, vector<int>& e2, int i, bool a, vector<vector<long long>>& dp1) {
    
        if (i >= e1.size()) {
            return 0;
        }
        if(dp1[i][a]!=-1){
            return dp1[i][a];
        }
        if (a) {
           
            long long continueWithA = e1[i] + solve(e1, e2, i + 1, true,dp1);
            long long switchToB = solve(e1, e2, i + 1, false,dp1);
            return dp1[i][a]=max(continueWithA, switchToB);
        } else {

            long long continueWithB = e2[i] + solve(e1, e2, i + 1, false,dp1);
         
            long long switchToA = solve(e1, e2, i + 1, true,dp1);
            return dp1[i][a]=max(continueWithB, switchToA);
        }
    }

    long long maxEnergyBoost(vector<int>& e1, vector<int>& e2) {
        int n = e1.size();
        vector<vector<long long>> dp1(n,vector<long long>(2,-1));

        return max(solve(e1, e2, 0, true,dp1), solve(e1, e2, 0, false,dp1));
    }
};
