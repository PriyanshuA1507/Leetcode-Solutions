class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> ans(n,vector<int>(n,0));
        int col = matrix[0].size()-1;
        int row = matrix.size()-1;
        int sr =0;

        while(col>=0){
         for(int i=0;i<matrix.size() && col>=0;i++){
            ans[i][col] = matrix[sr][i];
         }
         sr++;
         col--;
        }
        matrix = ans;
    }
};