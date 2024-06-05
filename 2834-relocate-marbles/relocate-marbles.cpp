class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& mf, vector<int>& mt) {
       unordered_set<int> positions(nums.begin(), nums.end());
        
        for (int i = 0; i < mf.size(); ++i) {
            if (positions.find(mf[i]) != positions.end()) {
                positions.erase(mf[i]);
                positions.insert(mt[i]);
            }
        }
        
        vector<int> result(positions.begin(), positions.end());
        sort(result.begin(), result.end());
        
        return result;
    }
};