class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& p) {
       queue<int> q;
       vector<int> ans;
    int count = 0;
    vector<int> indegree(n,0);
     unordered_map<int,vector<int>> adj;
     for(auto a:p){
     int u = a[0], v = a[1];
     adj[u].push_back(v);
     indegree[v]++;
     }   
     
     for(int i=0;i<n;i++){
     if(indegree[i]==0){
    ans.push_back(i);
      count++;
      q.push(i);
     }
     }

     while(q.size()!=0){
      auto a = q.front();
      q.pop();
      for(auto b:adj[a]){
      indegree[b]--;
      if(indegree[b]==0){
      q.push(b);
       ans.push_back(b);
      count++;
      }
      }
     }
     reverse(ans.begin(),ans.end());
     if(count==n){
        return ans;
     }
     return {};

    }
};