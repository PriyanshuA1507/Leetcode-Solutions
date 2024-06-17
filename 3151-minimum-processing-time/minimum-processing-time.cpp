class Solution {
public:
    int minProcessingTime(vector<int>& p, vector<int>& t) {
      sort(t.begin(),t.end());
      sort(p.begin(), p.end(), greater<int>());
      int maxi =INT_MIN;
      int j = 0;
      for(int i=0;i<t.size();i+=4){
        for(int k =0;k<4 && j < p.size();k++){
            maxi = max(t[i + k] + p[j], maxi);
        }  
        j++;
      }
   return maxi;
    }
};