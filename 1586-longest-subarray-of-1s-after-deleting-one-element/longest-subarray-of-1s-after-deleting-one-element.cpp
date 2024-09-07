class Solution {
public:
    int longestSubarray(vector<int>& nums) {
       int i=0, j=0;
       int ans = INT_MIN;
       int count =0;
       while(j<nums.size()){
        if(nums[j]==0){
         count++;
        }
        if(count==2){
         while(count!=1){
        if(nums[i]==0){
            i++;
            count--;
        }
        else{
         i++;
        }
         }
        }
        j++;
        ans = max(ans, j-i-1);
       }
       return ans;

    }
};