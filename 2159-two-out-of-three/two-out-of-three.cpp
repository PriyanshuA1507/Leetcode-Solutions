class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        unordered_map<int, int> m;
        set<int> a;
        vector<int> ans;

        for (int i = 0; i < nums1.size(); i++) {
            m[nums1[i]] = 1;
        }
        for (int i = 0; i < nums2.size(); i++) {
            if (m[nums2[i]] == 1) {
                a.insert(nums2[i]);
            } else if (m[nums2[i]] == 0) {
                m[nums2[i]] = 2;
            }
        }

        for (int i = 0; i < nums3.size(); i++) {
            if (m[nums3[i]] == 1 || m[nums3[i]] == 2) {
                a.insert(nums3[i]);
            }
        }

        ans.assign(a.begin(), a.end());
        return ans;
    }
};
