class Solution {
public:
    int maxProduct(vector<int>& nums) {
    int maxp = -1e8;
    int p = 1;
    for(auto a:nums){
    p*=a;
    maxp = max(p,maxp);
    if(p==0){
    p = 1;
    }
    }

    p = 1;
    for(int i= nums.size()-1;i>=0;i--){
     p*=nums[i];
     maxp = max(maxp,p);
     if(p==0){
     p = 1;
     }
    }
    return maxp;
    }
};