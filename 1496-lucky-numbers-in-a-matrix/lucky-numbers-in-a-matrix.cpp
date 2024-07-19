class Solution {
public:
    int minindex(vector<int> v)
    {
        int n=v.size();
        int minidx=0;
        int minvalue=v[0];
        for(int i=1;i<n;i++)
        {
            if(minvalue>v[i])
            {
                minvalue=v[i];
                minidx=i;
            }
        }
        return minidx;
    }
    int maxindex(vector<int> v)
    {
        int n=v.size();
        int maxidx=0;
        int maxvalue=v[0];
        for(int i=1;i<n;i++)
        {
            if(maxvalue<v[i])
            {
                maxvalue=v[i];
                maxidx=i;
            }
        }
        return maxidx;
    }
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> ans;
        set<pair<int,int>> s_min;
        set<pair<int,int>> s_max;
        int m=matrix.size();
        int n=matrix[0].size();
        for(int i=0;i<m;i++)
        {
            s_min.insert({i,minindex(matrix[i])});
        }
        for(int j=0;j<n;j++)
        {
            vector<int> v;
            for(int i=0;i<m;i++)
            {
                v.push_back(matrix[i][j]);
            }
            s_max.insert({maxindex(v),j});
        }
        for(auto i:s_min)
        {
            if(s_max.count(i)) ans.push_back(matrix[i.first][i.second]);
        }
        return ans;
    }
};