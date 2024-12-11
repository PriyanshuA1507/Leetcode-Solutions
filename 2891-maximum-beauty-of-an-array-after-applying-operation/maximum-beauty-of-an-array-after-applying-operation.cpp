class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int start = 0;
        int end = 0;
        int ans = INT_MIN;
        while(end<nums.size()){
        if(nums[end]-nums[start]<=2*k){
           ans = max(ans, end-start+1);
        }
        while(nums[end]-nums[start]>2*k){
         start++;
         if(nums[end]-nums[start]<=2*k){
            ans = max(ans,end-start+1);
         }
        }
        end++;
        }
        return ans;
    }
};