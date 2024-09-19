class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        if(k==0){
         if(nums1==nums2){
            return 0;
         }
         return -1;
        }
        long long negativeoperation=0, positiveoperation=0;
        for(int i=0;i<nums1.size();i++){
        long long diff = nums1[i]-nums2[i];
        if(diff%k!=0){
          return -1;
        }
        if(diff<0){
            negativeoperation+=diff/k;
        }
        if(diff>0){
            positiveoperation+=diff/k;
        }
        }
        if(negativeoperation+positiveoperation!=0){
            return -1;
        }
        return (-negativeoperation+positiveoperation)/2;
    }
};