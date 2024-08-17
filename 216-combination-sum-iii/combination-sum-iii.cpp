class Solution {
public:
   void solve(int k,int n,int sn,vector<int>& curr,vector<vector<int>>& ans){
    if(n==0 && curr.size()==k){
        ans.push_back(curr);
        return;
    }
    for(int i = sn;i<=9;i++){
     if(i>n || curr.size()==k){
        break;
     }
     curr.push_back(i);
     solve(k,n-i,i+1,curr,ans);
     curr.pop_back();
    }
   }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> curr;
        vector<vector<int>> ans;
      solve(k,n,1,curr,ans);  
      return ans;
    }
};