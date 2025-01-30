class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int sum = 0;
         for(auto a:cardPoints){
            sum+=a;
         }
        if(k>=cardPoints.size()){
            return sum;
        }
        int start = 0;
        int end = 0;
        int ans = INT_MIN;
        int sum2 = 0;
        while(end<cardPoints.size()){
         sum2+=cardPoints[end];
         if(end-start+1==n-k){
          ans = max(ans, sum-sum2);
         }
         else if(end-start+1>n-k){
         while(end-start+1>n-k){
          sum2-= cardPoints[start];
          start++;
         }
         ans = max(ans,sum-sum2);
         }
         end++;
        }
      return ans;
    }
};