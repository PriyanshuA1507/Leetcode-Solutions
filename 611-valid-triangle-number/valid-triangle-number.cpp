class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int ans=0;
       sort(nums.begin(),nums.end());
       for(int i=0;i<nums.size();i++){
        for(int j=i+1;j<nums.size();j++){
            int a = nums[i]+nums[j];
            int st = j+1, en = nums.size()-1;
            while(st<=en){
            int mid = st + (en-st)/2;
            if(nums[mid]<a){
             st  = mid+1;
            }
            else{
                en = mid-1;
            }
            }
            ans+=en-j;
        }
       }
       return ans; 
    }
};