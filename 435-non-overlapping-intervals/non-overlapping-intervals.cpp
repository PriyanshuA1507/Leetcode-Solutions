class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
   sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
     int ans = 0;
     int s = -1;
     int e =INT_MIN;
     for(int i=0;i<intervals.size();i++){
        if(e==INT_MIN || e<=intervals[i][0]){
         e = intervals[i][1];
         ans++;
        }
     }
     return intervals.size()-ans;   
    }
};