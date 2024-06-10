class Solution {
public:
    double trimMean(vector<int>& arr) {
       sort(arr.begin(),arr.end());
       int a = arr.size()/20;
       int sum = 0;
       int size = arr.size() - 2*a;
       for(int i = a;i<arr.size()-a;i++){
          sum+=arr[i];
       } 
       return (double)sum/(double)size;
    }
};