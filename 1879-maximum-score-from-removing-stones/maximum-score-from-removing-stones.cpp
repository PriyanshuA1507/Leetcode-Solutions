class Solution {
public:
    int maximumScore(int a, int b, int c) {
    int ans=0;
      priority_queue<int> pq;
      pq.push(a);
      pq.push(b);
      pq.push(c);
      while(pq.size()>1){
        int num1 = pq.top(); pq.pop();
        int num2 = pq.top(); pq.pop();
        if(num1-1>0) pq.push(num1-1);
        if(num2-1>0) pq.push(num2-1);
        ans+=1;
      } 
      return ans; 
    }
};