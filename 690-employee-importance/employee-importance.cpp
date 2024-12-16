/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
         unordered_map<int, bool> visited;
        unordered_map<int,int> m;
        for(auto a:employees){
         int id1 = a->id;
         int importance2 = a->importance;
         m[id1] = importance2;
        }
        unordered_map<int,vector<int>> adj;
        for(auto a: employees){
         int id1 = a->id;
         vector<int> b = a->subordinates;
         for(auto c:b){
          adj[id1].push_back(c);
         }
        }
        int sum = 0;
        queue<int> q;
        q.push(id);
        visited[id] = true;
        while(q.size()!=0){
         int id2 = q.front();
         q.pop();
         sum+=m[id2];
         for(auto a: adj[id2]){
            if(!visited[a]){
             visited[a] = true;
             q.push(a);
            }
         }
        }
        return sum;

    }
};