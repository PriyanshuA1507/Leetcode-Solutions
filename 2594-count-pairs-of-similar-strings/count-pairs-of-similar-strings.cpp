class Solution {
public:
    bool check(string a,string b){
        bool ans = true;
        unordered_map<int,int>m1,m2;
        for(int i=0;i<a.size();i++){
            m1[a[i]]++;
        }
        for(int i=0;i<b.size();i++){
            m2[b[i]]++;
        }
        for(int i=0;i<b.size();i++){
            if(m1[b[i]]<=0){
                ans = false;
                break;
            }
        }
        if(ans && m1.size()==m2.size()){
            return true;
        }
        return false;

    }
    int similarPairs(vector<string>& words) {
        int ans=0;
        for(int i=0;i<words.size();i++){
            for(int j=i+1;j<words.size();j++){
                if(check(words[i],words[j])){
                    ans++;
                }
            }
        }
        return ans;
    }
};