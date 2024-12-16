

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*> employeeMap;
        for (auto e : employees) {
            employeeMap[e->id] = e;
        }

        unordered_map<int, vector<int>> adj;
        for (auto a : employees) {
            int id1 = a->id;
            vector<int> b = a->subordinates;
            for (auto c : b) {
                adj[id1].push_back(c);
            }
        }

        unordered_map<int, bool> visited;
        int sum = 0;
        queue<int> q;
        q.push(id);
        visited[id] = true;

        while (!q.empty()) {
            int id2 = q.front();
            q.pop();
            sum += employeeMap[id2]->importance;
            for (auto a : adj[id2]) {
                if (!visited[a]) {
                    visited[a] = true;
                    q.push(a);
                }
            }
        }
        return sum;
    }
};
