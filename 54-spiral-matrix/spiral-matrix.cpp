class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
    int n = matrix.size();
    int m = matrix[0].size();
      int firstrow = 0;
      int lastcol = m-1;
      int lastrow = n-1;
      int firstcol = 0;
      while(ans.size()<m*n){
    //firstrow
    
      for(int i=firstcol;i<=lastcol && ans.size()<m*n;i++){
        ans.push_back(matrix[firstrow][i]);
      }
      firstrow++;
    
    //lastcol
    
      for(int i=firstrow;i<=lastrow && ans.size()<m*n;i++){
        ans.push_back(matrix[i][lastcol]);
      }
      lastcol--;
      
    //lastrow
      for(int i=lastcol;i>=firstcol  && ans.size()<m*n;i--){
        ans.push_back(matrix[lastrow][i]);
      }
    lastrow--;
      
    //firstcol

      for(int i=lastrow;i>=firstrow  && ans.size()<m*n;i--){
        ans.push_back(matrix[i][firstcol]);
      }
    firstcol++;
      
      }
        return ans;
    }
};