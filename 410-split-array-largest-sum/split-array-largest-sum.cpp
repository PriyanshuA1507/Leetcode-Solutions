class Solution {
public:
    bool possible(vector<int>& nums,int k,int mid){
    int p = 1;
    int sum = 0;
    for(auto a:nums){
     if(a>mid){
        return false;
     }
     if(sum + a > mid){
      p++;
      sum = a;
     }
     else{
        sum+=a;
     }
    }
    return p <= k;
    }
    int splitArray(vector<int>& nums, int k) {
     auto mini = *std::max_element(nums.begin(), nums.end());
     int maxi = 0;
     for(auto a:nums){
      maxi += a;
     }
     int ans = maxi;
     while(mini<=maxi){
     int mid = mini + (maxi-mini)/2;
     if(possible(nums,k,mid)){
     ans = min(ans,mid);
     maxi = mid-1;
     }
     else{
        mini = mid + 1;
     }
     }
        return ans;
    }
};