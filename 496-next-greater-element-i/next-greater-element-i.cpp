class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans2;
        unordered_map<int,int> m;
        for(int i=0;i<nums2.size();i++){
            m[nums2[i]] = i;
        }
        for(int i=0;i<nums1.size();i++){
        int j = m[nums1[i]];
        int ans = -1;
        for(int k=j;k<nums2.size();k++){
         if(nums2[k]>nums1[i]){
            ans = nums2[k];
            break;
         }
        }
        ans2.push_back(ans);
        }
        return ans2;
    }
};