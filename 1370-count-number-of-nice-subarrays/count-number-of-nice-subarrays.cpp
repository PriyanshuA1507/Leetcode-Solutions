class Solution {
public:
     int solve(vector<int>& nums, int k){
    int i = 0, j =0;
    int oc = 0;
    int ans =0;
    while(j<nums.size()){
    if(nums[j]%2!=0){
        oc++;
    }

    if(oc>k){
    while(oc>k){
    if(nums[i]%2!=0){
    oc--;
    }
    i++;
    }
    }
    ans += (j-i+1);
    j++;
    }
    return ans;
     }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return solve(nums,k)- solve(nums,k-1);
    }
};