class Solution {
public:
    vector<vector<int>> generate(int numRows) {
     if(numRows==1){
    return {{1}};
     }
    vector<vector<int>> ans = generate(numRows-1);
    vector<int> cr(numRows,1);
    vector<int> pr = ans.back();

    for(int i=1;i<numRows-1;i++){
     cr[i] = pr[i-1]+pr[i];
    }
    ans.push_back(cr);
    return ans;
    }
};