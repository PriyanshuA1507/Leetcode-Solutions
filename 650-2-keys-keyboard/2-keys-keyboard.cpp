class Solution {
public:
    int solve(int n,int i,int j){
        if(i>n)
        return 1e8;
        if(n==i){
            return 0;
        }
        int c = 1+ solve(n,2*i,i);
        int  p =  solve(n,i+j,j);
        return 1+min(c,p);
    }
    int minSteps(int n) {
        if(n<=1){
            return 0;
        }
        return 1+solve(n,1,1);
    }
};