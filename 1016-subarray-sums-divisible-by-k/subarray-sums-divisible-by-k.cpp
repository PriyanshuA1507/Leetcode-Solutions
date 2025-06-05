class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int ans = 0;
        int sum = 0;
        unordered_map<int,int> m;
        m[0] = 1;
        for(auto a:nums){
         sum = (sum+a)%k;
         if(sum<0){
          sum+=k;  
         }
         
          ans += m[sum];
        
         m[sum]++;
        }
        return ans;
    }
};