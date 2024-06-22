class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
       vector<int> a = arr;
       unordered_map<int,int>m;
       vector<int> ans(arr.size(),0);
       sort(a.begin(),a.end());
       int j = 1;
       for(int i=0;i<a.size();i++){
        if(m[a[i]]==0){
            m[a[i]]=j;
            j++;
        }
        m[a[i]]=m[a[i]];
       }
       for(int i=0;i<arr.size();i++){
        ans[i]= m[arr[i]];
       } 
       return ans;
    }
};