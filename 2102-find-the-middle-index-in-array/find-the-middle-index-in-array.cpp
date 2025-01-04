class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> psr(n+1);
        psr[n]= 0;
        vector<int> psl(n+1);
        psl[0] = 0;
        for(int i=0;i<n;i++){
         psl[i+1] = psl[i] + nums[i];
        }
         for (int i = n - 1; i >= 0; i--) {
            psr[i] = psr[i + 1] + nums[i];
        }
        for(int i=0;i<n;i++){
        if(psl[i]==psr[i+1]){
            return i;
        }
        }
        return -1;
    }
};