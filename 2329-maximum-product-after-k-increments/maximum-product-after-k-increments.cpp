class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        const int MOD = 1e9 + 7;
      priority_queue<int,vector<int>,greater<int>> pq;
      for(int i=0;i<nums.size();i++){
        pq.push(nums[i]);
      }  
      while(k-->0){
        int a= pq.top();
        pq.pop();
        a++;
        pq.push(a);
      }
      long long ans = 1;
      while(!pq.empty()){
      ans=(ans*pq.top())%MOD;
      pq.pop();
    }
    return ans;
    }
};