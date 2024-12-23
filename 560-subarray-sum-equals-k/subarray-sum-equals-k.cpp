class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
     unordered_map<int,int> m;
     m[0]=1;
     int cs = 0;
     int rs = 0;
     for(auto a:nums){
      cs+=a;
      int diff = cs-k;
      if(m[diff]>0){
        rs+=m[diff];
      }
      m[cs]++;
     }   
     return rs;
    }
};