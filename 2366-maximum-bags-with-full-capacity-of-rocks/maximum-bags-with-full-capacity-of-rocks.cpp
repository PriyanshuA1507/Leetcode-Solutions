class Solution {
public:

    int maximumBags(vector<int>& capacity, vector<int>& rocks, int ar) {
      priority_queue<int,vector<int>,greater<int>>pq;
      for(int i=0;i<rocks.size();i++){
        pq.push(capacity[i]-rocks[i]);
      }
      int ans = 0;
      while(ar>0 && pq.size()!=0){
        int a = pq.top();
        pq.pop();
        if(ar>=a){
            ar-=a;
            ans++;
        }
       else{
        break;
       }
      }
      return ans;
    }
};