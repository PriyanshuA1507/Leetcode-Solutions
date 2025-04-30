class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
      unordered_set<string> supplySet(supplies.begin(), supplies.end());
        unordered_map<string, vector<string>> graph;
        unordered_map<string, int> indegree;
        
        for (int i = 0; i < recipes.size(); ++i) {
            for (auto& ing : ingredients[i]) {
                graph[ing].push_back(recipes[i]);
                indegree[recipes[i]]++;
            }
        }

        queue<string> q;
        for (auto& item : supplies) {
            q.push(item);
        }

        vector<string> ans;
        while (!q.empty()) {
            string item = q.front();
            q.pop();

            for (auto& recipe : graph[item]) {
                indegree[recipe]--;
                if (indegree[recipe] == 0) {
                    ans.push_back(recipe);
                    q.push(recipe);
                }
            }
        }

        return ans;
    }
};