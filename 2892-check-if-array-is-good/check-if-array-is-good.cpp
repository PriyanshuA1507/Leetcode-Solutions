class Solution {
public:
    bool isGood(vector<int>& nums) {
        vector<int>ans;
        sort(nums.begin(),nums.end());
        int a = nums[nums.size()-1];
        for(int i=1;i<=a;i++){
            ans.push_back(i);
        }
        ans.push_back(a);
        if(ans == nums){
            return true;
        }
        return false;
        
    }
};