class Solution {
public:
    int findMin(vector<int>& arr) {
        int n = arr.size();
        int start = 0;
        int end = n-1;
        int ans = 1e8;
        while(start<=end){
        int mid = start + (end-start)/2;
     
         if(arr[start]<=arr[mid]){
         ans = min(ans,arr[start]);
            start = mid+1;
        }
        else if(arr[start]>=arr[mid]){
           ans = min(ans,arr[mid]);
            end = mid-1;
        }
        }
        return ans;
    }
};