class Solution {
public:
    int minSwaps(vector<int>& nums) {
        vector<int>arr(nums.size()*2,0);
        int ones=0;
        for(int i=0;i<nums.size();i++){
            arr[i]=nums[i];
            arr[nums.size()+i]=nums[i];
            if(nums[i]==1){
                ones++;
            }
        }
        if(ones<=1){
            return 0;
        }
        int zeros=0;
        int i=0;
        int j=0;
        int ans=nums.size();
        while(j<arr.size()){
            if(!arr[j]){
                zeros++;
            }
            if(j-i+1==ones){
                ans=min(ans,zeros);
                if(arr[i]==0){
                    zeros--;
                }
                i++;
            }
            j++;
        }
        return ans;
    }
};