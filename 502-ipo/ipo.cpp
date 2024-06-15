#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        // Priority queue to store projects based on the capital required
        auto comp = [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.first > b.first;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> pq(comp);
        
        // Fill the priority queue with initial projects
        for (int i = 0; i < profits.size(); ++i) {
            pq.push({capital[i], profits[i]});
        }
        
        // Priority queue to store available projects based on profits
        priority_queue<int> pq1;
        
        // Iterate k times to maximize the capital
        for (int i = 0; i < k; ++i) {
            // Move projects that can be done with current capital to pq1
            while (!pq.empty() && pq.top().first <= w) {
                pq1.push(pq.top().second);
                pq.pop();
            }
            
            // If no projects can be done, break the loop
            if (pq1.empty()) {
                break;
            }
            
            // Take the most profitable project
            w += pq1.top();
            pq1.pop();
        }
        
        return w;
    }
};
