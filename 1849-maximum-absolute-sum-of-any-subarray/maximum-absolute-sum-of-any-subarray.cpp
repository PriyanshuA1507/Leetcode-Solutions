class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxendingherepositive=nums[0];
        int maxendingherenegative=nums[0];
         int maxsofar = max(abs(nums[0]), 0);
        
        for(int i=1;i<nums.size();i++){
        maxendingherepositive = max(nums[i],maxendingherepositive +nums[i]);
        maxendingherenegative = min(nums[i],maxendingherenegative +nums[i]);
        maxsofar= max(maxsofar,max(abs(maxendingherepositive),abs(maxendingherenegative)));
        }
        return maxsofar;
    }
};