class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    if(nums.size()==1){
        return nums[0];
    }
     int sum=0;
     int largestsum=INT_MIN;
     for(int a:nums){
         sum+=a;
         largestsum=max(largestsum,sum);
          if(sum<0)     sum=0;        
     }
     return largestsum;   
    }
};