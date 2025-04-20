class Solution {
public:
    string uppercahalo(string a){
        string ans = "";
        stack<char> b;
        for(auto s:a){
         b.push(s);
        }
        while(b.size()!=0){
            ans+=b.top();
            b.pop();
        }
      return ans;
    }
    string reverseWords(string s) {
     string ans = "";
     string a= "";
     reverse(s.begin(),s.end());
     
     int end = 0;
     while(end<s.size()){
        if(s[end] != ' ') {
        a.push_back(s[end]);
        end++;
      }
      else{
       string b = uppercahalo(a);
       if(b!=""){
        ans+=b;
        ans+=" ";
       }
      end++;
     
      a = "";
      }
     }
     if(a.size()!=0){
      string b = uppercahalo(a); 
      ans+=b; 
     }
     while (!ans.empty() && ans.back() == ' ') {
            ans.pop_back();
        }
        

     return ans;   
    }
};