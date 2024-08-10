class Solution {
public:
     bool possible(vector<int>& b, int m, int k,int h){
        int ans = 0;
        for(int i=0;i<b.size();i++){
            int a=0;
         while(i<b.size() && b[i]<=h && a<k){
           a++;
           i++;
         }
         if(a==k){
            ans++;
            i--;
         }
        }
        if(ans>=m){
            return true;
        }
        return false;
     }
    int minDays(vector<int>& bloomday, int m, int k) {
       if((long long)m*k>bloomday.size()){
        return -1;
       } 
       int start = 0;
       int end = INT_MAX;
       int ans = -1;
       while(start<=end){
      int mid = (start+end)/2;
       if(possible(bloomday,m,k,mid)){
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