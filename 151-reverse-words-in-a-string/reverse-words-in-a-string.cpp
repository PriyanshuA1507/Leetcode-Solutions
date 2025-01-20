class Solution {
public:
     void reverse2(stack<int>& s1, string& a){
     while(s1.size()!=0){
     a.push_back(s1.top());
     s1.pop();
     }
     a.push_back(' ');
     }
    string reverseWords(string s) {
        string a;
        stack<int> s1;
     reverse(s.begin(),s.end());
     for(int i=0;i<s.size();i++){
     while(i<s.size()&& s[i]!=' '){
     s1.push(s[i]);
     i++;
     }
     if(s1.size()!=0){
     reverse2(s1,a);
     }
     }
     a.pop_back();
     return a; 
    }
};