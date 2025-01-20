class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
         if (nums.size() == 1 && target == nums[0]) {
            return {0, 0};
        }
        int start=0;
        int end = nums.size()-1;
        while(start<=end){
        int m = (start+end)/2;
        if(nums[m]==target){
        int left = m, right = m;
        while(left>0 && nums[left-1]==target){
         left--;
        }
         while(right<nums.size()-1 && nums[right+1]==target){
         right++;
        }
        return {left,right};
        }
        else if(nums[m]>target){
         end = m-1;
        }
        else if(nums[m]<target){
            start = m+1;
        }
        }
        return {-1,-1};
    }
};