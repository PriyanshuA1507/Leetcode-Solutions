class Solution {
public:
    bool check(int a,int b){
     int max1 =-1;
     int max2 = -1;
     while(a>0){
     if(a%10>max1)max1 = a%10;
     a=a/10;
     }
     while(b>0){
     if(b%10>max2)max2 = b%10;
     b=b/10;
     }
     if(max1==max2){
        return true;
     }
     return false;
    }
    int maxSum(vector<int>& nums) {
        int ans=-1;
        for(int i=0;i<nums.size()-1;i++){
            for(int j=i+1;j<nums.size();j++){
            if(check(nums[i],nums[j])){
                ans = max(ans,nums[i]+nums[j]);
            }
            }
        }
        return ans;
    }
};