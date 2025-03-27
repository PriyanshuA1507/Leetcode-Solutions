class Solution {
public:
    int minimumIndex(vector<int>& nums) {
     unordered_map<int,int> m;
     for(auto a:nums){
        m[a]++;
     }
     int maxinumber = -1;
     int maxicount = -1;

     for(auto a:m){
      if(a.second>maxicount){
       maxicount = a.second;
       maxinumber = a.first;
      }
     }
     unordered_map<int,int> a;
     int count = 0;
     for(int i=0;i<nums.size();i++){
     if(nums[i]==maxinumber){
     count++;
     }
     a[i] = count;
     }
     for(int i=0;i<nums.size()-1;i++){
      if(a[i]>(i+1)/2 && (a[nums.size()-1] - a[i])>(nums.size()-i-1)/2){
        return i;
      }
     }
     return -1;
    }
};