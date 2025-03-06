class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
int n = grid.size();
        vector<int>vec(n*n +1,0);
        for(auto & it: grid){
            for(auto & i: it){
                vec[i]++;
            }
        }
        int a,b;
        for(int i=1;i<=n*n;i++){
            if(vec[i]==2) a = i;
            if(vec[i]==0) b = i;
        }
        return {a,b};
    }
};