class Solution {
public:
    int solve(int ci,int pi,int d,vector<int>& nums){
    if(ci>=nums.size()){
        return 0;
    }
    int take = 0;
    if(nums[ci]-nums[pi]==d){
     take = 1 + solve(ci+1,ci,d,nums);
    }
    return take ;
    }
    int numberOfArithmeticSlices(vector<int>& nums) {
      if(nums.size()<3){
        return 0;
      }  
      int ans = 0;
      for(int i=0;i<nums.size();i++){
       for(int j=i+1;j<nums.size();j++){
       ans+=(solve(j+1,j,nums[j]-nums[i],nums));
       break;
       }
      }
      return ans;
    }
};