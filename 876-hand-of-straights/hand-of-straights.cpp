class Solution {
public:

    bool isNStraightHand(vector<int>& hand, int gs) {
        priority_queue<int,vector<int>,greater<int>> pq;
        unordered_map<int,int> m;
        for(int i=0;i<hand.size();i++){
          pq.push(hand[i]);
         m[hand[i]]++;
        }
        while(pq.size()!=0){
        int start = pq.top();
        pq.pop();
        if(m[start]==0){
        continue;
        }
        for(int i=0;i<gs;i++){
        if(m[start]==0){
        return false;
        }
        m[start]--;
        start++;
        }
        }
        return true;
    }
};