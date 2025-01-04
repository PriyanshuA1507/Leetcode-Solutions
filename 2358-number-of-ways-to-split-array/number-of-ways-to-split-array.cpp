class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        vector<long long> pfl(n+1);
        pfl[0] = 0;
        vector<long long> pfr(n+1);
        pfr[n] = 0;
        for(int i=0;i<n;i++){
            pfl[i+1] = pfl[i]+ nums[i];
        }
        for(int j=n-1;j>=0;j--){
         pfr[j] = pfr[j+1] + nums[j];
        }
        for(int i=1;i<n;i++){
         if(pfl[i]>=pfr[i]){
            ans++;
         }
        }
       
        return ans;
    }
};