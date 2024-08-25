class Solution {
public:
    typedef pair<int,int> p;
    vector<int> getFinalState(vector<int>& nums, int k, int m) {
        int n = nums.size();
        priority_queue<p,vector<p>,greater<p>> pq;
        for(int i=0;i<nums.size();i++){
            pq.push({nums[i],i});
        }
        while(k-->0){
         auto a = pq.top();
         pq.pop();
         pq.push({a.first*m,a.second});
        }
        vector<int> result(n,0);
        while(pq.size()!=0){
             auto a = pq.top();
             pq.pop();
             result[a.second] = a.first;
        }
        return result;
    }
};