class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& p) {
        //1.  indegree;
        unordered_map<int,vector<int>>m;
        vector<int> indegree(n,0);
        for(auto& a:p){
           m[a[0]].push_back(a[1]);
           indegree[a[1]]++;
        }
    //2. indegree 0
      queue<int> q;
      for(int i=0;i<n;i++){
        if(indegree[i]==0){
            q.push(i);
        }
      }
      int result = 0;
     while(!q.empty()){
        int a = q.front();
        q.pop();
        result++;
        for(auto& a1:m[a]){
          indegree[a1]--;
          if(indegree[a1]==0){
            q.push(a1);
          }
        }
     }
     if(result==n){
        return true;
     }
     return false;
    }
};