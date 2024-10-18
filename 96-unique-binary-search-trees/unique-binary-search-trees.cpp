class Solution {
public:
   int numTrees1(int n,vector<int>& dp) {
    if(n<=1){
        return 1;
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
    ans += numTrees1(i-1,dp)*numTrees1(n-i,dp);
    }
    return ans;   
    }
    int numTrees(int n) {
     vector<int> dp(n+1,-1);
     return numTrees1(n,dp);
    }
};