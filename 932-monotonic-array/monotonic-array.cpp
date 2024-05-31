class Solution {
public:
     bool i(vector<int> nums){
    bool ans = true;
    for(int i=0;i<nums.size()-1;i++){
        if(nums[i+1]<nums[i]){
            ans = false;
            break;
        }
    }
    return ans;
     }
     bool d(vector<int> nums){
    bool ans = true;
    for(int i=0;i<nums.size()-1;i++){
        if(nums[i+1]>nums[i]){
            ans = false;
            break;
        }
    }
    return ans;
     }
    bool isMonotonic(vector<int>& nums) {
        if(i(nums) || d(nums)){
         return true;
        }
        return false;
    }
};