class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back({newInterval[0],newInterval[1]});
         sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });
        vector<vector<int>> ans;
        int s = intervals[0][0];
        int e = intervals[0][1];
        ans.push_back({s,e});
        for(int i=1;i<intervals.size();i++){
            int n = ans.size();
            if(ans[n-1][1]>=intervals[i][0]){
                e = max(intervals[i][1],e);
                s = min(s,intervals[i][0]);
                ans[n-1][0] = s;
                ans[n-1][1] = e;
            }
            else{
            ans.push_back({intervals[i][0],intervals[i][1]});
            s = intervals[i][0];
            e = intervals[i][1];
            }
        }
        return ans;

    }
};