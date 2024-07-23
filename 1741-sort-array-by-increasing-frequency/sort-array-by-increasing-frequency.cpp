class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        priority_queue<pair<int,int>> pq;
        for( auto it:m){
            pq.push({-it.second,it.first});
        }
        vector<int> result;
        while(!pq.empty()){
            int x = pq.top().first;
            for(int i=0;i<abs(x);i++){
                result.push_back(pq.top().second);
            }
            pq.pop();
        }
        return result;
    }
};