class Solution {
public:
    vector<int> findOrder(int nc, vector<vector<int>>& prerequisites) {
      vector<int> indegree(nc,0);
        unordered_map<int,vector<int>>adj;
        queue<int> q;
        for(auto a:prerequisites){
          int u = a[0];
          int v = a[1];
          adj[u].push_back(v);
          indegree[v]++;
                }
        for(int i=0;i<nc;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        int count = 0;
        vector<int> ans;
        while(q.size()!=0){
         int a = q.front();
         q.pop();
         count++;
         ans.push_back(a);
         for(auto b:adj[a]){
          indegree[b]--;
          if(indegree[b]==0){
           q.push(b);
          }
         }
        }
        if(count==nc){
            reverse(ans.begin(),ans.end());
            return ans;
        }

         return {};
           
    }
};