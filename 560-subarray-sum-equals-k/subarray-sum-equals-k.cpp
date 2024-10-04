class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
       unordered_map<int,int>m;
       m[0]=1;
       int cs = 0 ,res=0;
       for(int a: nums){
        cs+=a;
        int diff = cs-k;
        if(m.find(diff)!=m.end()){
            res+=m[diff];
        }
        m[cs]++;
       }
       return res;
    }
};