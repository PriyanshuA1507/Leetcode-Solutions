class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double ans = -DBL_MAX;
        int start = 0;
        int end = 0;
        double sum=0;
        while(end<nums.size()){
            sum+=nums[end];
            end++;
            if(end-start==k){
              ans = max(ans,sum/k);
              sum-=nums[start];
              start++;
            }
        }
        return ans;
    }
};