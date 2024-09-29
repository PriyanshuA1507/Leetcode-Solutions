class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        unordered_map<int,int>m;
        if(nums.size()%k!=0){
            return false;
        }
        for(int i=0;i<nums.size();i++){
        m[nums[i]]++;
    }
        for(int i=0;i<n;i++){
         if(m[nums[i]]<=0){
            continue;
         }
         for(int j = nums[i];j<nums[i]+k;j++){
            if(m[j]<=0){
                return false;
            }
            m[j]--;
         }
        }
        return true;
    }
};