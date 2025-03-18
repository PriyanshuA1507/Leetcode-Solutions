class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int ans = 1;
        for(int i=0;i<nums.size();i++){
            long long xr = 0;
            for(int j=i;j<nums.size();j++){
                if((xr^nums[j]) == xr+nums[j]){ 
                    xr ^= nums[j];
                    if(j==nums.size()-1) ans = max(ans,j-i+1);
                }
                else{
                    ans = max(ans,j-i);
                    break;
                }
            }
        }
        return ans;
    }
};