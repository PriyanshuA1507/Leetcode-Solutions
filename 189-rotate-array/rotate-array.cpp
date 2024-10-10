class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;
       /* while(k-->0){
            vector<int> n1(n,0);
            int p = nums[0];
        for(int i=0;i<nums.size();i++){
        n1[(i+1)%n] = nums[i];
        }
        nums = n1;
        n1.clear();
        }*/
    reverse(nums.begin() ,nums.end());
    reverse(nums.begin(),nums.begin()+k);
    reverse(nums.begin()+k,nums.end());
    }
};