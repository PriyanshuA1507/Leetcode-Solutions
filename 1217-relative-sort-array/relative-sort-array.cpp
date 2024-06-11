class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
      vector<int> c;
      int s=0;

      
      for(int i=0;i<arr2.size();i++){
       for(int j=0;j<arr1.size();j++){
         if(arr2[i]==arr1[j]){
             c.push_back(arr2[i]);
             arr1[j]=-1;   
         }
         s++;
       }   
      }
      sort(arr1.begin(),arr1.end());
     for(int k=c.size();k<arr1.size();k++){
         c.push_back(arr1[k]);
     }
      return c;  
    }
};
