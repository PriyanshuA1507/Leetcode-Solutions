class Solution {
public:
    bool check(int mid,vector<int>& nums,int k){
    int p = 1;
    int cs = 0;
    for(auto a:nums){
      if(cs+a>mid){
       cs = a;
       p++;
       if(p>k){
        return false;
       }
      }
      else{
        cs+=a;
      }
    }
    return k>=p;
    }
    int splitArray(vector<int>& nums, int k) {
    int ans =0;
     int start = *max_element(nums.begin(),nums.end());
     int end = 0;
     for(auto a:nums){
        end+=a;
     }
     while(start<=end){
    int mid = start + (end-start)/2;
     if(check(mid,nums,k)){
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