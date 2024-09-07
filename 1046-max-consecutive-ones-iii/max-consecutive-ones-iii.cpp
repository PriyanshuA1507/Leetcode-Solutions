class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i =0, j = 0;
        int ans = INT_MIN;
        unordered_map<int,int> m;
        while(j<nums.size()){
         m[nums[j]]++;
        
            while(m[0]>k){
                m[nums[i]]--;
                if(m[nums[i]]==0){
                    m.erase(nums[i]);
                }
                i++;
         }
         ans = max(ans, j-i+1);
         j++;
        }
        return ans;
    }
};