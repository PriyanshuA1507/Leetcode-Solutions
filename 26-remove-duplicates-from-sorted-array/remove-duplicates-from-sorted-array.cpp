class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> m;
        for(int i=0;i<nums.size();i++){
            m.insert(nums[i]);
        }
        nums.clear();
             for (int elem : m) {
            nums.push_back(elem);
        }
       return m.size();
    }
};