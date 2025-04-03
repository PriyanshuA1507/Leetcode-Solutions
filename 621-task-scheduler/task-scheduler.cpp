class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
       unordered_map<char,int> m;
       for(auto a:tasks){
        m[a]++;
       } 
       priority_queue<int> pq;
       for(auto a:m){
        pq.push(a.second);
       }
      int time = 0;
       while(pq.size()!=0){
        vector<int> temp;
        for(int i=1;i<=n+1;i++){
        if (!pq.empty()) {
                    temp.push_back(pq.top() - 1); 
                    pq.pop();
                }
        }
        for(auto t:temp){
         if(t>0){
          pq.push(t);
         }
        }
        if(pq.size()!=0){
         time+=(n+1);
        }
        else{
        time+=temp.size();
        }
       }
       return time;
    }
};