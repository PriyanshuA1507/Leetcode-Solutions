class Solution {
public:
    int maxProfit(vector<int>& prices) {
    int ans = 0;
     int miniprice = prices[0];
     //miniprice = 7
     for(int i=0;i<prices.size();i++){
    
       miniprice = min(miniprice,prices[i]); 
    //miniprice = 1
       ans = max(ans,prices[i]-miniprice);
    //ans = max(0,4-1); ans =5
     }
     return ans;    
    }
};