class Solution {
public:
    bool possible(vector<int>& weights, int days,int m){
        long long ans = 1;
        int cw=0;
        for(int i=0;i<weights.size();i++){
            if(cw+weights[i]>m){
               ans++;
               cw = weights[i];
               if(ans>days){
                return false;
               }
            }
             else{
                cw+=weights[i];
               }
        }
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int start = *max_element(weights.begin(), weights.end());
        long long end = 0;
        for(int i=0;i<weights.size();i++){
            end+=weights[i];
        }
        int ans = 0;
        while(start<=end){
         int mid = (start+end)/2;
         if(possible(weights,days,mid)){
            ans = mid;
            end = mid-1;
         }
         else{
            start = mid+1;
         }
        }
        return ans;
    }
};