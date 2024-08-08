class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
       vector<int> a(n,0);
       int start = 0;
       for(int i=0;i<nums.size();i++){
        if(nums[i]!=0){
            a[start] = nums[i];
            start++;
        }
       }
       nums =a;
    }
};