class Solution {
public:
    bool divideArray(vector<int>& nums) {
          bool a=true;
      unordered_map<int,int> m;
      for(int i=0;i<nums.size();i++){
         if(m[nums[i]]>0){
             m[nums[i]]+=1;
         }
         else m[nums[i]]=1;
      }
      if(nums.size()%2==0){
       for(int j=0;j<nums.size();j++){
           if(m[nums[j]]%2!=0){
               a=false;
               break;
           }
       }   
      }
    if(nums.size()%2!=0){
        a=false;
    }
    return a;
    }
};