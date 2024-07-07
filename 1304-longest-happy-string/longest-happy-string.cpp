class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
      priority_queue<pair<int,char>> pq;
      string ans="";
      if(a>0)pq.push({a,'a'});
      if(b>0)pq.push({b,'b'});
      if(c>0)pq.push({c,'c'});
      while(!pq.empty()){
        int fn = pq.top().first;
        int fc = pq.top().second;
        pq.pop();
        if(ans.size()>0 && ans.back()!=fc){
           int t = min(fn,2);
           for(int i=0;i<t;i++){
            ans+=fc;
           }
           fn-=t;
        }
        else if(ans.size()==0){
           int t = min(fn,2);
           for(int i=0;i<t;i++){
            ans+=fc;
           }
           fn-=t;
        }
        else{
         if(pq.size()==0)
         break;
         int f2 = pq.top().first;
         char c = pq.top().second;
         pq.pop();
         ans+=c;
         f2--;
         if(f2>0)
         pq.push({f2,c});
        }
        if(fn>0){
            pq.push({fn,fc});
        }
      }
      return ans;
    }
};