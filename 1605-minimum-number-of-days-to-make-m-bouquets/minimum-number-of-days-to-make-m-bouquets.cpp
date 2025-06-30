class Solution {
public:
     bool cp(vector<int>& b, int m, int k,int mid){
    int bo = 0;
    int f = 0;
    for(auto c:b){
     if(c<=mid){
        f++;
        if(f==k){
        bo++;
        f=0;
        }
     }else{
        f = 0;
     }
    }
    return bo>=m;
     }
    int minDays(vector<int>& b, int m, int k) {
      if(b.size()<(long long)m*k){
        return -1;
      }  
      int ans = 0;
      int start = 1;
      int end = 0;
      for(auto a:b){
        end = max(end,a);
      }
    
      while(start<=end){
     int mid = start + (end-start)/2;
     if(cp(b,m,k,mid)){
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