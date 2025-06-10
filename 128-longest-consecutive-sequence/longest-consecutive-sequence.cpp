class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
         if (nums.empty()) return 0;
        unordered_set<int> s(nums.begin(),nums.end());
       int ans = 0;
        for(auto a:s){
         if(s.find(a-1)==s.end()){
         int count = 1;
          int num = a;
          while(s.find(num+1)!=s.end()){
            count++;
            num++;
          }
          ans = max(ans,count);
         }
        }
        
        return ans;
    }
};