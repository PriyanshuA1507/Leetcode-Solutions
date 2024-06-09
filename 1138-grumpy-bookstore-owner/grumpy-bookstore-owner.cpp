class Solution {
public:
    int maxSatisfied(vector<int>& c, vector<int>& grumpy, int m) {
       int start=0;
       int end = 0;
       int ans = INT_MIN;
       int sum = 0;
       while(end<grumpy.size()){
          if(grumpy[end]==1){
            sum+=c[end];
          }
       
         if(end -start+1 ==m){
         ans = max(ans,sum);
          if(grumpy[start]==1){
          sum-=c[start];
          }
          start++;
         }
         end++;
       }
        for (int i=0; i<c.size(); i++){
            if (grumpy[i]==0){
                ans += c[i];
            }
        }
       return ans; 
    }
};