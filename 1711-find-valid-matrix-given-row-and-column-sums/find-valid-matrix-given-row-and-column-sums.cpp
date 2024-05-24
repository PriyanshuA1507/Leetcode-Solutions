class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
      int rows = rowSum.size();
      int cols = colSum.size();
      vector<vector<int>> a(rows, vector<int>(cols));
      for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
         a[i][j] = min(rowSum[i],colSum[j]);
         rowSum[i] -= a[i][j];
         colSum[j] -= a[i][j];
        }
      }  
      return a;
    }
};