class Solution {
public: 
   using p = pair<int,int>;
    vector<int> topKFrequent(vector<int>& nums, int k) {
    vector<int> ans;
    unordered_map<int,int> m;
    for(auto a:nums){
    m[a]++;
    }
    priority_queue<p> pq;
    for(auto a:m){
    pq.push({a.second,a.first});
    }
    while(k>0 && pq.size()!=0){
    ans.push_back(pq.top().second);
    pq.pop();
    k--;
    }
    return ans;

    }
};