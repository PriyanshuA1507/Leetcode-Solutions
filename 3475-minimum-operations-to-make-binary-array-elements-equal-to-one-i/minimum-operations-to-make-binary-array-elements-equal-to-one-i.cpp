class Solution {
public:
    int minOperations(vector<int>& nums) {
       int ans = 0;
       for(int i=0;i<nums.size();i++){
        if(nums[i]==0 && i+2<nums.size()){
            nums[i]=1;
            nums[i+1] = (!nums[i+1]);
             nums[i+2] = (!nums[i+2]);
            ans++;
        }
       else if(nums[i]==0 && i+2>=nums.size()){
            ans = -1;
            break;
        }
       } 
       return ans;
    }
};