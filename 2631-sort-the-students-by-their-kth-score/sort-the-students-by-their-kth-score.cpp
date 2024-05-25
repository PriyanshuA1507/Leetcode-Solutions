class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        vector<vector<int>> ans;
        vector<pair<int,int>> a;
        int n =score.size();
        int m = score[0].size();
        for(int i=0;i<score.size();i++){
            a.push_back(make_pair(score[i][k],i));
        }
        sort(a.begin(),a.end());
        for(int i=n-1;i>=0;i--){
            ans.push_back(score[a[i].second]);
        }
        return ans;  
    }
};