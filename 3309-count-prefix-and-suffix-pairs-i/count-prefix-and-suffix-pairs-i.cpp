class Solution {
public:
   bool check(string a, string b) {
    if(b.size()>=a.size()){
    string c = b.substr(0, a.size());
    string d = b.substr(b.size() - a.size(), a.size());
    if (a == c && a == d) {
        return true;
    }
    }
    return false;
}
    int countPrefixSuffixPairs(vector<string>& words) {
        int ans = 0;
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