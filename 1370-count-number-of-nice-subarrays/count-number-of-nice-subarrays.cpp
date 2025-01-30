class Solution {
public:
    int solve(vector<int>& nums, int k){
    int start = 0;
    int end = 0;
    int ans = 0;
    int oc=0;
    while(end<nums.size()){ 
     if(nums[end]%2==1){
     oc++;
    }

    while(oc>k){
    if(nums[start]%2==1){
      oc--;
    }
    start++;
    }
    ans+=(end-start+1);
    end++;
    }
    return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
       return solve(nums,k) - solve(nums,k-1); 
    }
};