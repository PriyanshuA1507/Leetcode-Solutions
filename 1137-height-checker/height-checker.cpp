class Solution {
public:
    int heightChecker(vector<int>& heights) {
       vector<int> a = heights;
       sort(a.begin(),a.end());
       int ans=0;
       for(int i=0;i<heights.size();i++){
        if(a[i]!=heights[i]){
            ans++;
        }
       }
       return ans; 
    }
};