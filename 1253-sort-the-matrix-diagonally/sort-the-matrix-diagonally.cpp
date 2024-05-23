class Solution {
public:
    void change(vector<vector<int>>& mat, int row,int col){
       vector<int> a;
        int r = row, c = col;
        
      
        while (r < mat.size() && c < mat[0].size()) {
            a.push_back(mat[r][c]);
            r++;
            c++;
        }
        
 
        sort(a.begin(), a.end());
   
        r = row;
        c = col;
        int index = 0;
        while (r < mat.size() && c < mat[0].size()) {
            mat[r][c] = a[index];
            r++;
            c++;
            index++;
        }
    }
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
       for(int i = mat.size()-1;i>=0;i--){
          change(mat,i,0);
       }
       for(int i = 1;i<mat[0].size();i++){
          change(mat,0,i);
       }
       return mat;

    }
};