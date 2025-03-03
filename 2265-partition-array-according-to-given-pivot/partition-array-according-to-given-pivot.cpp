class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> a;
        vector<int> b;
        vector<int> c;
       for(int i=0;i<nums.size();i++){
           if(nums[i]<pivot){
               a.push_back(nums[i]);
           }
           else if(nums[i]>pivot)
           { b.push_back(nums[i]);}
           else{ c.push_back(nums[i]);}
       }
  
       nums.clear();
       for(int i=0;i<a.size();i++){
           nums.push_back(a[i]);
       }
       for(int i=0;i<c.size();i++){
           nums.push_back(c[i]);
       }
       for(int i=0;i<b.size();i++){
           nums.push_back(b[i]);
       }
       return nums;
    }
};