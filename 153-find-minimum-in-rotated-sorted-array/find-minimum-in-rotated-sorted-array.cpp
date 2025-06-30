class Solution {
public:
    int findMin(vector<int>& nums) {
       int start = 0;
       int end = nums.size()-1;
       int ans = 1e8;
       while(start<=end){
       int mid = start + (end-start)/2;
       if(nums[start]<=nums[mid]){
        ans = min(ans,nums[start]);
        start = mid+1;
       }
       else if(nums[start]>=nums[mid]) {
        ans = min(ans,nums[mid]);
         end = mid-1;
       }
       }
       return  ans;
    }
};