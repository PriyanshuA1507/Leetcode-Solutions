class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int ans = 0;
      unordered_map<int,int> m;
      for(int a: arr1){
      while(m[a]<=0 && a>0){
        m[a]++;
        a = a/10;
      }
      }
      for(int b: arr2){
        while(m[b]<=0 && b>0){
            b= b/10;
        }
        if(b>0){
            ans = max(ans, static_cast<int>(log10(b))+1);
        }
      }  
        return ans;
    }
};