class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
       int ans = 0;
       vector<int> chosenIndices;
       priority_queue<pair<int, int>> pq;

       // Calculate the difference between reward1 and reward2 and store it in the priority queue
       for (int i = 0; i < reward1.size(); i++) {
           pq.push({reward1[i] - reward2[i], i});
       }

       // Pick the top k differences
       while (k-- > 0) {
           int idx = pq.top().second;
           ans += reward1[idx];  // Take the reward1 value for the chosen k items
           chosenIndices.push_back(idx);
           pq.pop();
       }

       // Set the selected indices to 0 in reward2
       for (int idx : chosenIndices) {
           reward2[idx] = 0;
       }

       // Add the remaining rewards from reward2
       for (int r : reward2) {
           ans += r;
       }

       return ans;
    }
};
