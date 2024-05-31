
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
   int m=mat.size(); 
      int n=mat[0].size();
      int row=0;
      int col=0;
      bool up=true;
      //The above are some intilisations;
      vector<int>result;
      while(row<m and col<n){
          if(up==true){
              //when we are moving in the up direction
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
             //when we are moving in the down direction
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
         up=!up; //reversing the condition to move in alternate direction
      }
    return result;
    }
};
