class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& p) {
        //1.  indegree;
        unordered_map<int,vector<int>>m;
        vector<int> indegree(n,0);
        for(auto& a:p){
           m[a[1]].push_back(a[0]);
           indegree[a[0]]++;
        }
    //2. indegree 0
      queue<int> q;
      for(int i=0;i<n;i++){
        if(indegree[i]==0){
            q.push(i);
        }
      }
      vector<int> ans;
      int result = 0;
     while(!q.empty()){
        int a = q.front();
        q.pop();
        ans.push_back(a);
        result++;
        for(auto& a1:m[a]){
          indegree[a1]--;
          if(indegree[a1]==0){
            q.push(a1);
          }
        }
     }
     if(result!=n){
     ans.clear();
     }
     return ans;
    
    }
};