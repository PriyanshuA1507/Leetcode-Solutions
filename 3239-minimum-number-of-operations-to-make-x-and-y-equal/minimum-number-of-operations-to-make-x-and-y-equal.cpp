class Solution {
public:
    int bfs(int x, int y) {
        queue<pair<int, int>> q; 
        unordered_set<int> visited;

        q.push({x, 0});
        visited.insert(x);

        while (!q.empty()) {
            auto [a, steps] = q.front();
            q.pop();

            if (a == y) return steps;

        
            if (a % 11 == 0) {
                int next = a / 11;
                if (visited.find(next) == visited.end()) {
                    q.push({next, steps + 1});
                    visited.insert(next);
                }
            }

            if (a % 5 == 0) {
                int next = a / 5;
                if (visited.find(next) == visited.end()) {
                    q.push({next, steps + 1});
                    visited.insert(next);
                }
            }

            if (a - 1 >= 0 && visited.find(a - 1) == visited.end()) {
                q.push({a - 1, steps + 1});
                visited.insert(a - 1);
            }

            if (visited.find(a + 1) == visited.end()) {
                q.push({a + 1, steps + 1});
                visited.insert(a + 1);
            }
        }

        return -1; 
    }

    int minimumOperationsToMakeEqual(int x, int y) {
        if (y > x) {
            return y - x; 
        } else {
            return bfs(x, y);
        }
    }
};