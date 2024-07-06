class Solution {
public:
    long long maximumPoints(vector<int>& e, int ce) {
         sort(e.begin(), e.end());
      if (e.empty() || e[0]>ce) {
            return 0;
        }
        
        
        long long ce1 = ce;
        for (int i = 1; i < e.size(); ++i) {
            ce1 += e[i];
        }
        
        return ce1 / e[0];
   
    }
};