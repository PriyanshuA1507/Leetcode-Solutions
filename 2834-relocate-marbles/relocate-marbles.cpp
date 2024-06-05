class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& mf, vector<int>& mt) {
       set<int> p;
       for(int i=0;i<nums.size();i++){
        p.insert(nums[i]);
       }
        for (int i = 0; i < mf.size(); ++i) {
            if (p.find(mf[i]) != p.end()) {
                p.erase(mf[i]);
                p.insert(mt[i]);
            }
        }
        
        vector<int> result(p.begin(), p.end());
        
        return result;
    }
};