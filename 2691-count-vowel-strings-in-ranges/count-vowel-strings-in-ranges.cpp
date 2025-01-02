class Solution {
    bool check(string s){
        int n = s.size() - 1;
        if((s[0] == 'a' || s[0] == 'e' || s[0] == 'i' || s[0] == 'o' || s[0] == 'u') && 
                (s[n] == 'a' || s[n] == 'e' || s[n] == 'i' || s[n] == 'o' || s[n] == 'u'))
        { 
            return true;
        }
        return false;
    }
  
public:
    std::vector<int> vowelStrings(std::vector<std::string>& words, std::vector<std::vector<int>>& queries) {
        std::vector<int> a(words.size(), 0); 
        for(int i = 0; i < words.size(); i++){
            if(check(words[i])){
                a[i] = 1;
            }
        }
      
        for(int i=1;i<a.size();i++){
            a[i]=a[i]+a[i-1];
        }
       vector<int>ans;
        for(int i=0;i<queries.size();i++){
            int r=queries[i][1];
            int l=queries[i][0];
            if(l>0){
                ans.push_back(a[r]-a[l-1]);
            }else{
                ans.push_back(a[r]);
            }
        }
        return ans;
    }
};