class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int max=pow(2,maximumBit)-1;
        vector<int> a(nums.size(),0);
        a[0]=nums[0];
        int b=a[0];
        for(int i=1;i<nums.size();i++){
         a[i]=b^nums[i];
         b=a[i];
        }
       reverse(a.begin(),a.end());
       vector<int> ans;
        for(int i=0;i<a.size();i++){
            if(a[i]==max){
                ans.push_back(0);
            }
            else { ans.push_back(max-a[i]);}
        }
        return ans;
    }
};