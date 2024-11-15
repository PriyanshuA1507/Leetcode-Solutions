class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& pr) {
     unordered_map<int,vector<int>> m;
     queue<int> q;
     vector<int> result;
     vector<int> indegree(numCourses,0);
     for(int i=0;i<pr.size();i++){
    int u = pr[i][0];
    int v = pr[i][1];
    m[u].push_back(v);
    indegree[v]++;
     }
   for(int i=0;i<numCourses;i++){
    if(indegree[i]==0){
     q.push(i);
    }
   }
   while(q.size()!=0){
    int a = q.front();
    result.push_back(a);
    q.pop();
    for(auto b: m[a]){
    indegree[b]--;
    if(indegree[b]==0){
        q.push(b);
    }
    }
   }
   if(result.size()==numCourses){
    return true;
   }
   return false;
    }
};