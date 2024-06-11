class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
    vector<int> a;
    priority_queue<pair<int,int>,vector<pair<int,int>> ,greater<pair<int,int>>> pq;
    for(int i=0;i<nums.size();i++){
      pq.push({nums[i],i});
      if(pq.size()>k){
        pq.pop();
      }
    }
    priority_queue<pair<int,int>,vector<pair<int,int>> ,greater<pair<int,int>>> temp;
    while(!pq.empty()){
        temp.push({pq.top().second,pq.top().first});
        pq.pop();
    }

    while(!temp.empty()){
    a.push_back(temp.top().second);
    temp.pop();
    }
    return a;
    }
};