class Solution {
public:
    int lis(vector<int>& nums){
        if(nums.size()==0){
            return 0;
        }
        int maxLen=1;
        int currLen=1;
         for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[i] < nums[i + 1]) {
                currLen++; 
            } else {
                maxLen = max(maxLen, currLen); 
                currLen = 1; 
            }
        }
        
        maxLen = max(maxLen, currLen);
        
        return maxLen;
    }
     int lds(vector<int>& nums){
        if(nums.size()==0){
            return 0;
        }
        int maxLen=1;
        int currLen=1;
         for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[i] > nums[i + 1]) {
                currLen++; 
            } else {
                maxLen = max(maxLen, currLen); 
                currLen = 1; 
            }
        }
        
        maxLen = max(maxLen, currLen);
        
        return maxLen;
    }
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans = max(lis(nums),lds(nums));
        return ans;
        
    }
};