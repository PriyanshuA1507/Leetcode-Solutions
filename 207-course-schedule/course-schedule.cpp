class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& p) {
       vector<int> indegree(numCourses,0);
       queue<int> q;
       unordered_map<int,vector<int>> adj;
       for(auto a: p){
      int u = a[0], v = a[1];
       adj[u].push_back(v);
       indegree[v]++;
       }
       int c=0;
       for(int i=0;i<numCourses;i++){
        if(indegree[i]==0){
        c++;
         q.push(i);
        }
       }
       while(q.size()!=0){
      int u = q.front();
       q.pop();
       for(auto v: adj[u]){
      indegree[v]--;
      if(indegree[v]==0){
        c++;
        q.push(v);
      }
       }
       }
       if(c==numCourses){
        return true;
       }
       return false;
    }
};