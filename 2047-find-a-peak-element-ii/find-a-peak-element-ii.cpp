class Solution {
public:
    bool possible(int a,vector<vector<int>>& mat,int r,int c){
        int rows = mat.size();
        int cols = mat[0].size();
        
        if (r + 1 < rows && mat[r + 1][c] >= a) {
            return false;
        }
        if (r - 1 >= 0 && mat[r - 1][c] >= a) {
            return false;
        }
        if (c + 1 < cols && mat[r][c + 1] >= a) {
            return false;
        }
        if (c - 1 >= 0 && mat[r][c - 1] >= a) {
            return false;
        }
        
        return true;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        vector<int> ans;
        bool a = true;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(possible(mat[i][j],mat, i, j)){
                 ans.push_back(i);
                ans.push_back(j);
                a= false;
                 break;
                }
            }
            if(!a){
                break;
            }
        }
        return ans;
    }
};