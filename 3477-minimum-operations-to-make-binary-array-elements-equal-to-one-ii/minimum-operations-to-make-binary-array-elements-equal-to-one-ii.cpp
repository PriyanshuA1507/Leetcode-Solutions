class Solution {
public:
    int minOperations(vector<int>& nums) {
       int ans = 0;
       int check0 = true;
       int check1 = false;
       for(int i=0;i<nums.size();i++){
        if(nums[i]==0 && check0){
           check0=false;
           check1 = true;
          ans++;  
        }
        else if(nums[i]==1 && check1){
            check1 = false;
            check0 = true;
            ans++;
        }
       } 
       return ans;
    }
};