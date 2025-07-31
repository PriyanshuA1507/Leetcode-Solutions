class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
     int start = 0;
     int end = 0;
     int ans = 0;
     unordered_map<int,int> m;
     while(end<nums.size()){
      m[nums[end]]++;
      if(m[0]<=k){
       ans = max(ans,(end - start + 1));
      }
      if(m[0]>k){
      while(m[0]>k){
       m[nums[start]]--;
       start++;
       if(m[0]==0){
       m.erase(0);
       } 
      }
      ans = max(ans,(end-start+1));
      }
      end++;
     }
     return ans;
    }
};