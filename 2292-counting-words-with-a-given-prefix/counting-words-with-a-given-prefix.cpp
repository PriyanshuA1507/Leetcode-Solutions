class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int ans = 0;
        for(int i=0;i<words.size();i++){
            string a = words[i];
            bool a1 = true;
            for(int j=0;j<pref.size();j++){
                if(a[j]!=pref[j]){
                    a1 = false;
                    break;
                }
            }
            if(a1){ans++;}
        }
        return ans;
    }
};