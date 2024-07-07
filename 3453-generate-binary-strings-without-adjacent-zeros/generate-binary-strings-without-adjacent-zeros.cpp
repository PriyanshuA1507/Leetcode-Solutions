class Solution {
public:
    vector<string> validStrings(int n) {
        if(n==1){
            return {"0","1"};
        }
        vector<string> a = validStrings(n-1);
        vector<string> ans;
        for(int i=0;i<a.size();i++){
            string c = a[i];
            if(c.back()=='0'){
                ans.push_back(c+'1');
            }
            else{ ans.push_back(c+'1');
                   ans.push_back(c+'0');
        }
        }
       return ans;
    }
};