class Solution {
public:
   using p = tuple<int, int, int, int>;
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>m;
        for(int i=0;i<n;i++){
         for(int j=i+1;j<n;j++){
          int a = nums[i]*nums[j];
          m[a]++;
        }
        }
        int ans = 0;
        for(auto a:m){
        if(a.second>1){
         ans += (a.second * (a.second - 1) / 2) * 8;
        }
        }
       return ans;
    }
};