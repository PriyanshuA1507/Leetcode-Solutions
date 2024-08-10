class Solution {
public:
   bool possible(vector<int>& piles, long h,long mid){
   long ans = 0;
   for(int i=0;i<piles.size();i++){
    if(mid!=0 && piles[i]%mid==0){
        ans+=(piles[i]/mid);
    }
    else if(mid!=0 && piles[i]%mid!=0){
        ans+=(piles[i]/mid +1);
    }
   }
   if(h>=ans){
    return true;
   }
   return false;
   }
    int minEatingSpeed(vector<int>& piles, int h) {
    int n = piles.size();
     sort(piles.begin(),piles.end());
     long left = 1;
     long right = piles[n-1];
     long ans = 0;
     while(left<=right){
      long mid = (left+right)/2;
      if(possible(piles,h,mid)){
        ans = mid;
        right = mid-1;
      }
      else{
        left = mid+1;
      }
     }
     return ans;   
    }
};