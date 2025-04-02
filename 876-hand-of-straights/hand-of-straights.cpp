class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int gs) {
    priority_queue<int,vector<int>,greater<int>>pq;
     if(hand.size()%gs!=0){
        return false;
     }
     unordered_map<int,int>m;
     for(auto a:hand){
        pq.push(a);
        m[a]++;
     }
     while(pq.size()!=0){
       int start = pq.top();
        pq.pop();
      if(m[start]==0){
       continue;
      }
      for(int i=0;i<gs;i++){
      if(m[start+i]<=0){
        return false;
      }
      m[start+i]--;
      }
     }
     return true;
    }
};