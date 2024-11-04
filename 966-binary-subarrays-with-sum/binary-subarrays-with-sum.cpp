class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
      unordered_map<int,int> pfc;
      pfc[0] = 1;
      int sum = 0;
      int count = 0;
      for(int num: nums){
        sum+=num;
        if(pfc.find(sum-goal)!=pfc.end()){
            count+=pfc[sum-goal];
        }
        pfc[sum]++;
      }
      return count; 
    }
};