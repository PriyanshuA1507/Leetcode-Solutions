class Solution {
public:
   static bool cmp(const vector<int>& a, const vector<int>& b){
    return a[1]<b[1];
   }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
       if(intervals.empty()) return 0;

       sort(intervals.begin() , intervals.end(),cmp);
       int cnt = 0 , last = intervals[0][1];

       for(int i=1;i<intervals.size();i++){
       if(intervals[i][0]>= last){
        last = intervals[i][1];
       }
       else{
       cnt++;
       }
       }
       return cnt;

    }
};