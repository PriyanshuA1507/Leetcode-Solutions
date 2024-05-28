class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
      vector<int> result(n, -1);
       vector<int> ans;
       vector<pair<int,int>> start;
       vector<int> end;
       for(int i=0;i<intervals.size();i++){
        start.push_back({intervals[i][0],i});
        end.push_back(intervals[i][1]);
       }
       sort(start.begin(),start.end());
       for(int i=0;i<end.size();i++){
         int end = intervals[i][1];
            int left = 0, right = n;
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (start[mid].first >= end) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            }
            if (left < n) {
                result[i] = start[left].second;
            }
       }
       return result;
    }
};