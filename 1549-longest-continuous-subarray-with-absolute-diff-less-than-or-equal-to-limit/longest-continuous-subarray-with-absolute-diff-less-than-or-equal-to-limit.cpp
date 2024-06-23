class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int ans=0;
        multiset<int> s;
        for(int start=0,end=0;end<nums.size();end++){
            s.insert(nums[end]);
            while(*s.rbegin() - *s.begin()>limit){
                s.erase(s.find(nums[start++]));
            }
            ans  = max(ans,end-start+1);
        }
        return ans;
    }
};