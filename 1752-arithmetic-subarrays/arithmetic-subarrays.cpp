class Solution {
public:
    bool check(vector<int>& a) {
        if (a.size() < 2) return false;  
        sort(a.begin(), a.end());
        int difference = a[1] - a[0];
        for (int i = 1; i < a.size() - 1; i++) {
            if (a[i + 1] - a[i] != difference) {
                return false;
            }
        }
        return true;
    }

    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans;
        for (int i = 0; i < l.size(); i++) {
            vector<int> a(nums.begin() + l[i], nums.begin() + r[i] + 1);
            ans.push_back(check(a));
        }
        return ans;
    }
};
