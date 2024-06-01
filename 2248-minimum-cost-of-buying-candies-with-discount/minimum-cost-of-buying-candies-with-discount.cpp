class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int ans=0;
        if(cost.size()==1){
            return cost[0];
        }
        if(cost.size()==2){
            return cost[0]+cost[1];
        }
        sort(cost.begin(),cost.end(),greater<int>());
        int i=0;
        while(i<cost.size()){
        ans += cost[i];
            i++;
            if (i < cost.size()) { 
                ans += cost[i];
            }
            i += 2;
        }
        return ans;
    }
};