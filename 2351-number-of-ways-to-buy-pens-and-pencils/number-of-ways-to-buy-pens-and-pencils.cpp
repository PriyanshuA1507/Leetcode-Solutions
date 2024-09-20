class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        long long ans = 0;
        int pen = 0;
        while(pen*cost1<=total){
         if(total-pen*cost1>=0){
            ans+= 1 + (total-pen*cost1)/cost2;
         }
         pen++;
        }
       return ans;
        
    }
};