class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int>m1;
        m1[0]=1;
        int cs=0,res=0;
        for(int i=0;i<nums.size();i++){
            cs+=nums[i];
            int diff=cs-k;
            if(m1.find(diff)!=m1.end()){
                res+=m1[diff];
            }
            m1[cs]++;
        }
        return res;
    }
};