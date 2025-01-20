class Solution {
public:
     bool check(int mid,vector<int>& nums, int k){
     int a = 1;
     int sum=0;
     for(int i=0;i<nums.size();i++){
     if(nums[i]>mid){
      return false;
     }
     if(sum+nums[i]>mid){
     a++;
     sum = nums[i];
     if(a>k){
        return false;
     }
     }else{
    sum+=nums[i];
     }
     }
     return true;
    }
    int splitArray(vector<int>& nums, int k) {
        int start = *max_element(nums.begin(),nums.end());
        int end = 0;
        int ans = 0;
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
