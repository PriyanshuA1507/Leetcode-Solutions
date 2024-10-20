class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        int ls = 0;
        int ans = INT_MIN;
        for(int a: nums){
            ls+=a;
            ans = max(ans,ls);
            if(ls<0){
            ls=0;
            }
        }
        return ans;
    }
};