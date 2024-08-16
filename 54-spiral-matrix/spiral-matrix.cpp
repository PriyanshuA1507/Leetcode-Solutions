class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int row=matrix.size();
     int col=matrix[0].size();
     int count = 0;
     int total= row*col;
     vector<int> ans;

     //intialisation
     int startingrow=0;
     int startingcol=0;
     int lastrow=row-1;
     int lastcol=col-1;
     while(count<total){
        //starting row
        for(int i = startingcol;count<total && i<=lastcol;i++){
            ans.push_back(matrix[startingrow][i]);
            count++;
        }
        startingrow++;
        //lastcol
        for(int i = startingrow;count<total && i<=lastrow;i++){
            ans.push_back(matrix[i][lastcol]);
            count++;
        }
        lastcol--;
        //lastrow
        for(int i=lastcol;count<total && i>=startingcol;i--){
            ans.push_back(matrix[lastrow][i]);
            count++;
        }
        lastrow--;
        //firstcol
        for(int i=lastrow;count<total && i>=startingrow;i--){
            ans.push_back(matrix[i][startingcol]);
            count++;
        }
        startingcol++;
     }
     return ans;
    }
};