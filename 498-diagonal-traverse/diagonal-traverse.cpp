
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
   int m=mat.size(); 
      int n=mat[0].size();
      int row=0;
      int col=0;
      bool up=true;
      
      vector<int>result;
      while(row<m and col<n){
          if(up==true){
           
              while(row>0 and col<n-1){
               result.push_back(mat[row][col]);
               row--;
               col++;
              }
              result.push_back(mat[row][col]);
              if(col==n-1){
                  row++;
              }
              else{
                  col++;
              }
          }
         else{
             while(col>0 and row<m-1){
                 result.push_back(mat[row][col]);
                 row++;
                 col--;
             }
             result.push_back(mat[row][col]);
             if(row==m-1){
                 col++;
             }
             else{
                 row++;
             }
         }
         up=!up; 
      }
    return result;
    }
};
