class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int ans =0;
            auto comp = [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.first > b.first;
        };
        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(comp)>pq(comp);
        for(int i=0;i<profits.size();i++){
            pq.push({capital[i],profits[i]});
        }
        int i=0;
        priority_queue<int> pq1;
       for(int i=0;i<k;++i){
        while(!pq.empty() && pq.top().first<=w){
            pq1.push(pq.top().second);
            pq.pop();
          
        }
        if(pq1.empty()){
            break;
        }
        w+=pq1.top();
        pq1.pop();
        }
        return w;
    }
};