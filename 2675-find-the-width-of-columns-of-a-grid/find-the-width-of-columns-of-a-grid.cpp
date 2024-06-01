class Solution {
public:
   string itos(int num) {
        return to_string(num);
    }
   int length(int a){
    int l=0;
    if(a<0){
        l++;
        a=-a;
    }
    string c = itos(a);
    return l+c.size();
   }
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        vector<int>a;
        for(int i=0;i<grid[0].size();i++){
            int maxi = 0;
            for(int j=0;j<grid.size();j++){
               maxi = max(maxi,length(grid[j][i]));
            }
            a.push_back(maxi);
        }
        return a;
    }
};