class Solution {
public:
    int dp[101][101];
    bool solverec(string &s1, string &s2, string &s3,int idx1,int idx2){
        if(s1.length()+s2.length()!=s3.length()){
            return dp[idx1][idx2]=0;
        }
        if(idx1==s1.length()&&idx2==s2.length()){
            return dp[idx1][idx2]=1;
        }
        if (dp[idx1][idx2] != -1) {
            return dp[idx1][idx2];
        }
        bool op1=1;
        bool op2=1;
        if(s1[idx1]==s3[idx1+idx2]){
            op1&=(solverec(s1,s2,s3,idx1+1,idx2));
            if(op1==1){
                return dp[idx1][idx2]=1;
            }
        }
        if(s2[idx2]==s3[idx1+idx2]){
            op2&=(solverec(s1,s2,s3,idx1,idx2+1));
            if(op2==1){
                return dp[idx1][idx2]=1;
            }
        }
        return dp[idx1][idx2]=0;
    }
    bool isInterleave(string s1, string s2, string s3) {
        memset(dp,-1,sizeof(dp));
        return solverec(s1,s2,s3,0,0);
    }
};