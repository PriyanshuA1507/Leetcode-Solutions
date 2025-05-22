class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
     int n = nums.size();
     vector<int> lp(n,1);
     vector<int> rp(n,1);
     
     int leftproduct = 1;
     for(int i=1;i<n;i++){
      leftproduct*=nums[i-1];
      lp[i] = leftproduct;
     }
     
     int rightproduct = 1;
     for(int i=n-2;i>=0;i--){
      rightproduct*=nums[i+1];
      rp[i] = rightproduct;
     }
     vector<int> ans(n);
     for(int i=0;i<n;i++){
     ans[i] = lp[i]*rp[i];
     }
     return ans;
    }
};