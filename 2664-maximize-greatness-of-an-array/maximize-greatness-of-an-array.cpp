class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    int st =0;
    int en =1;
    int cnt =0;
    while(en<nums.size()){
     while(en<nums.size() && nums[en]<=nums[st]){
        en++;
     }
     if(en == nums.size()){
        break;
     }
     st++;
     en++;
     cnt++;
    }
    return cnt;
    }
};