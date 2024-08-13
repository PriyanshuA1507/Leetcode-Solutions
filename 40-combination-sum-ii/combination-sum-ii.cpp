class Solution {
public:
   void solve(vector<int>& c, int t,int s, vector<int>& current, vector<vector<int>>& result){
       if(t==0){
        result.push_back(current);
       }
       for(int i=s;i<c.size();i++){
           if(i>s && c[i]==c[i-1]){
               continue;
           }
           if(c[i]>t){
               break;
           }
           current.push_back(c[i]);
           solve(c,t-c[i],i+1,current,result);
           current.pop_back();
       }
   }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> result;
        vector<int> curr;
        solve(candidates,target,0,curr,result);
        return result;
    }
};