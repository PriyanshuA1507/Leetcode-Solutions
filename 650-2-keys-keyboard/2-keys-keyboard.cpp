class Solution {
public:
    int solve(int n, int ol,int cl){
        if(ol>n){
            return 1e9;
        }
        if(ol==n){
            return 0;
        }
        
       
       int c1 = 2 + solve(n,2*ol,ol);
       
       int p = 1 + solve(n,ol+cl,cl);

       return  min(c1,p);
    }
    int minSteps(int n) {
        if(n<=1){
            return 0;
        }
       int ol = 1;
       int cl = 1;
    return 1+solve(n,1,1);
    }
};