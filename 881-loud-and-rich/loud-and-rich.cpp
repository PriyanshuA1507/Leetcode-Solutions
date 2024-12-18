class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        queue<int> q;
        vector<int> indegree(n,0);
        vector<int> answer(n);
        for(int i=0;i<n;i++){
            answer[i] = i;
        }
        unordered_map<int,vector<int>> adj;
        for(auto a:richer){
        adj[a[0]].push_back(a[1]);
        indegree[a[1]]++;
        }
        for(int i=0;i<n;i++){
          if(indegree[i]==0){
            q.push(i);
          }
        }
        while(q.size()!=0){
        int u = q.front();
        q.pop();
        for(auto v:adj[u]){
        if(quiet[answer[u]]<quiet[answer[v]]){
            answer[v] = answer[u];
        }
        indegree[v]--;
        if(indegree[v]==0){
        q.push(v);
        }
        }
        }
        return answer;
    }
};