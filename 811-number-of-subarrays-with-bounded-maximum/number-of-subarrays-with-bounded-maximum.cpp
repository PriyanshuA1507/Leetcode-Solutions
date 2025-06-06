class Solution {
public:
    int count(vector<int>& nums,int v){
    int cnt = 0;
    int ans = 0;
    for(auto a:nums){
    if(a<=v){
    cnt = cnt+1;
    }
    else{
        cnt = 0;
    }
    ans +=cnt;
    }
    return ans;
    }
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        return count(nums,right) -count(nums,left-1);
    }
};