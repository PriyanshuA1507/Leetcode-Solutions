class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
       int ans=0;
        priority_queue<int>pq1,pq2;
        for(int i=0;i<players.size();i++){
            pq1.push(players[i]);
        }
        for(int i=0;i<trainers.size();i++){
            pq2.push(trainers[i]);
        }
        while(pq2.size()>0 && pq1.size()>0){
           if(pq2.top()>=pq1.top()){
               ans++;
               pq1.pop();
               pq2.pop();
           }
           else{ pq1.pop();}
        }
        return ans;
    }
};