class Solution {
public:
    bool possible(vector<int>& weights, int days,int mid){
        int a = 1;
        int c = 0;
        for(auto d:weights){
        if(c+d>mid){
            a++;
            c = d;
        }
        else{
            c+=d;
        }
        }
        return a<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int start = 0;
        long long end = 0;
        for(int i=0;i<weights.size();i++){
             start = max(start, weights[i]);
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
