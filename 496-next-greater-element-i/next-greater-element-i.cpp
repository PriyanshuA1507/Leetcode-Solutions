class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> m;
        for(int i=0;i<nums2.size();i++){
            m[nums2[i]]=i;
        }
        for(int i=0;i<nums1.size();i++){
            int a = nums1[i];
            bool c = false;
         for(int j = m[a];j<nums2.size();j++){
            if(a<nums2[j]){
                nums1[i]=nums2[j];
                c = true;
                break;
            }
         } 
         if(!c){
            nums1[i] = -1;
         }
        }
        return nums1;
        
    }
};