class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;  
        vector<int> a(n);

        for(int i=0;i<k;i++){
        a[i] = nums[nums.size()-k+i];
        }
        for(int i=k;i<nums.size();i++){
            a[i] = nums[i-k];
        }
     nums = a;
    }
};