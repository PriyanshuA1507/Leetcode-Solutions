class Solution {
public:
    vector<vector<int>>ans;
    void solverec(vector<int>a,vector<int>subset,int start){
        ans.push_back(subset);
        
        for(int i=start;i<a.size();i++){
            if(i!=start&&a[i]==a[i-1]){
                continue;
            }
            subset.push_back(a[i]);
            solverec(a,subset,i+1);
            subset.pop_back();
            
        }
    }
    vector<vector<int>>subsetsWithDup(vector<int>a){
        vector<int>an;
        sort(a.begin(),a.end());
        solverec(a,an,0);
        return ans;
    }
    
};