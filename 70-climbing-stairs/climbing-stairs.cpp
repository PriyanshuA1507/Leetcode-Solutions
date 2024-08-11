class Solution {
public:
    
    int solve(int n, int i,vector<int>& v) {
        
        if (i == n) {
            return 1;
        }
          if (i > n) {
            return 0;
        }
        if(v[i]!=-1){
            return v[i];
        }

      
        return v[i]=solve(n, i + 1,v) + solve(n, i + 2,v);
    }


    int climbStairs(int n) {
        vector<int> a(n,-1);
        return solve(n, 0,a);
    }
};
