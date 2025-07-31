class Solution {
public:
    int totalFruit(vector<int>& f) {
     unordered_map<int,int> m;
      int start = 0;
      int end = 0;
      int ans = 0;
      while(end<f.size()){
      m[f[end]]++;
      if(m.size()<=2){
      ans = max(ans, end-start+1);
      }
      
      if(m.size()>2){
      while(m.size()>2){
       m[f[start]]--;
       if(m[f[start]]==0){
       m.erase(f[start]);
       }
       start++;
      }
       ans = max(ans, end-start+1);
      }
      end++;
      }
      return ans;   
    }
};