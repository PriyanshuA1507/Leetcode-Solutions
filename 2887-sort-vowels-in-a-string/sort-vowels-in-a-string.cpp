class Solution {
public:
   bool isvowel(char c) {
        c = tolower(c); 
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    string sortVowels(string s) {
    string a;
    for(int i=0;i<s.size();i++){
        if(isvowel(s[i])){
            a.push_back(s[i]);
        }
    }
   sort(a.begin(),a.end());
   int start = 0;
   for(int i=0;i<s.size();i++){
    if(isvowel(s[i])){
        s[i]=a[start];
        start++;
    }
   }
   return s;
    }
};