class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        priority_queue<pair<int,int>>pq;
        for(auto x:m){
            pq.push({x.second,x.first});
        }
        vector<int> ans;
        while(k-->0){
            int f = pq.top().first;
           int i= pq.top().second;
           pq.pop();
           ans.push_back(i);
        }
        return ans;
    }
};