class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
     unordered_map<int,int> m;
     m[0]=1;
     int sum=0;
     int ans = 0;
     for(int a:nums){
     sum+=a;
     if(m[sum-k]>0){
     ans+=m[sum-k];
     }
     m[sum]++;
     }        
     return ans;                                                                               
    }
};