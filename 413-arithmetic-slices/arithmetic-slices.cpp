class Solution {
public:
   int solve(vector<int>& nums,int index,int d,int pi,int n){
    if(index>=n || nums[index]-nums[pi]!=d){
        return 0;
    }
    return  1 + solve(nums,index+1,d,index,n);

   }
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if(n<3){
            return 0;
        }

        int ans = 0;
        for(int i=0;i<n-2;i++){
        int d = nums[i+1] - nums[i];
        ans+=solve(nums,i+2,d,i+1,n);
        }
        return ans;
    }
};