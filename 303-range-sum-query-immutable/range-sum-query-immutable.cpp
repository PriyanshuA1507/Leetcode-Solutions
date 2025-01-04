class NumArray {
public:
 vector<int> a;
    NumArray(vector<int>& nums) {
        int n = nums.size();
        a.resize(n+1);
        a[0] = 0;
        for(int i=0;i<n;i++){
            a[i+1] = a[i] + nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        return a[right+1]-a[left];
        
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */