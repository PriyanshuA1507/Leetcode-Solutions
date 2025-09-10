class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int ans = 0;
        vector<int> mp(26,0);
        for(auto a:tasks){
         mp[a-'A']++;
        }

        priority_queue<int> pq;
        for(auto a:mp){
        if(a > 0){
        pq.push(a);
        }
        }

        while(pq.size()!=0){
            vector<int> temp;
        for(int i=1;i<=n+1;i++){
         if(!pq.empty()){
           temp.push_back(pq.top() -1);
            pq.pop();
         } 
        }
        for(auto a:temp){
        if(a>0){
        pq.push(a);
        }
        }

        if(pq.size()==0){
        ans += temp.size();
        }
        else{
        ans += (n+1);
        }
        }
        return ans;
    }
};