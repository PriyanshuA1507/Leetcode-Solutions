class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        if(changed.size()%2!=0){
            return {};
        }
        vector<int> ans1;
        int n = changed.size();
        vector<int> ans;
        unordered_map<int,int>m;
        for(int i=0;i<changed.size();i++){
            m[changed[i]]++; 
        }
        sort(changed.begin(),changed.end());
        for(int i=0;i<changed.size();i++){
         if(changed[i]>0 && m[changed[i]]>0 && m[changed[i]*2]>0 ){
            ans.push_back(changed[i]);
            m[changed[i]*2]-=1;
            m[changed[i]]-=1;
         }
         if(changed[i]==0 && m[changed[i]]>=2){
            ans.push_back(changed[i]);
            m[changed[i]]-=2;
         }
        }
    if(ans.size()==n/2)   
    return ans;
    else
    return ans1;
    }
};