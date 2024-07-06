class Solution {
public:
    int passThePillow(int n, int time) {
      int ans = 1;
      int a = -1;
      while(time-->0){
        if(ans == n || ans==1 ){
        a*=-1;
        }
            ans+=a;
        
      }
      return ans;  
    }
};