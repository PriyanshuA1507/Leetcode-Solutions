class Solution {
public:
    int addRungs(vector<int>& rungs, int dist) {
      int a=0;
      long long start = 0;
      for(int i=0;i<rungs.size();i++){
       if(rungs[i]-start>dist){
       a+=(rungs[i]-start-1)/dist;
       } 
       start = rungs[i];
      }
      return a;  
    }
};