class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& r) {
        int max = -1;
        int ans = 0;
        for(int i=0;i<r.size();i++){
            if(max<(min(r[i][0],r[i][1]))){
                max = min(r[i][0],r[i][1]);
            }
        }
        for(int i=0;i<r.size();i++){
            if(max==(min(r[i][0],r[i][1]))){
                ans++;
            }
        }
   return ans;
    }
};