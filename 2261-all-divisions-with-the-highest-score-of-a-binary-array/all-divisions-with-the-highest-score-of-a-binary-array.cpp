class Solution {
public:
   vector<int> pz1(vector<int>& nums){
    int n = nums.size();
   vector<int> pz(n+1,0);
    for(int i=0;i<nums.size();i++){
        if(nums[i]==0){
         pz[i+1] = 1+pz[i];
        }
        else{
            pz[i+1] = pz[i];
        }
    }
    return pz;
   }
   vector<int> po1(vector<int>& nums){
    int n = nums.size();
   vector<int> po(n+1,0);
    for(int i=nums.size()-1;i>=0;i--){
        if(nums[i]==1){
         po[i] = 1+po[i+1];
        }
        else{
            po[i] = po[i+1];
        }
    }
    return po;
   }
    vector<int> maxScoreIndices(vector<int>& nums) {
     vector<int> result;
     vector<int> po = po1(nums);
     vector<int> pz = pz1(nums);
     vector<int> score(nums.size()+1,0);
     int maxi = -1;
     for(int i=0;i<=nums.size();i++){
        score[i]=po[i]+pz[i];
        if(score[i]>maxi){
            maxi = score[i];
        }
     }
     for(int i=0;i<score.size();i++){
        if(maxi==score[i]){
            result.push_back(i);
        }
     }
  return result;
    }
};