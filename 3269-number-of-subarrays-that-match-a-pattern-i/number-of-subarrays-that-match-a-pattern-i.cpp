class Solution {
public:
    bool check(vector<int> a, vector<int> p){
        bool ans = true;
        for(int i=0;i<p.size();i++){
            if(p[i]==1 && a[i+1]<=a[i]){
                ans= false;
                break;
            }
            if(p[i]==0 && a[i+1]!=a[i]){
                ans= false;
                break;
            }
            if(p[i]==-1 && a[i+1]>=a[i]){
                ans= false;
                break;
            }
        }
        return ans;
    }
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int n = nums.size();
        int m  = pattern.size();
        int ans = 0;
        for(int i = 0; i <= n - (m + 1); ++i){
       vector<int> a(nums.begin() + i, nums.begin() + i + m + 1);
            if (check(a, pattern)) {
                ++ans;
            }
        }
        return ans;
    }
};