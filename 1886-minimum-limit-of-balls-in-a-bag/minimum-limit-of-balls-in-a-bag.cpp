class Solution {
public:
    bool check(int mid,vector<int>& nums, int mo){
        int ro =0;
        for(int i=0;i<nums.size();i++){
         if(nums[i]>mid){
            ro+=(nums[i]-1)/mid;
         }
        }
        if(ro<=mo){
            return true;
        }
        return false;
    }
    int minimumSize(vector<int>& nums, int mo) {
    int start=1;
    int end = *std::max_element(nums.begin(), nums.end());
    int mid = start + (end-start)/2;
    while(start<end){
    if(check(mid,nums,mo)){
        end = mid;
    }
    else{
        start = mid+1;
    }
    mid = start+(end-start)/2;
    }
   return start;
    }
};