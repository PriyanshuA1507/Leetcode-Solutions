class Solution {
public:
    bool check(vector<int>& nums) {
        int a = 0;
        int size = nums.size();
        if(size==1){
            return true;
        }
        vector<int> nums1;
        for(int i=0;i<nums.size();i++){
            nums1.push_back(nums[i]);
        }
        for(int i=0;i<nums.size();i++){
            nums1.push_back(nums[i]);
        }
        for(int i=0;i<nums1.size()-1;i++){
            if(nums1[i]<=nums1[i+1] && a<size){
                a++;
                if(a==size-1)
                break;
            }
            else if(nums1[i]>nums1[i+1]){
                a = 0;
            }
        }
        if(a==size-1)
        return true;
        return false;
    }
};