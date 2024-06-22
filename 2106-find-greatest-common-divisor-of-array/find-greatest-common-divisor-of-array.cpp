class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for(int i=0;i<nums.size();i++){
           if(mini>nums[i]){
            mini=nums[i];
           }
            if(maxi<nums[i]){
            maxi=nums[i];
           }
        }
        return gcd(mini,maxi);
            }
};