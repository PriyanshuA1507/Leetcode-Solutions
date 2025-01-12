class Solution {
public:
    bool canBeValid(string s, string locked) {
        if(s.size()%2!=0){
            return false;
        }
        stack<int> open;
        stack<int> openclose;

        for(int i=0;i<s.size();i++){
        if(locked[i]=='0'){
            openclose.push(i);
         }
         else if(s[i]=='('){
          open.push(i);
         }
         else if(s[i]==')'){
           if (open.size()!=0){
            open.pop();
          }
          else if(openclose.size()!=0){
            openclose.pop();
          }
          else {
            return false;
          }
         }
        }
        while(open.size()!=0 && openclose.size()!=0 && open.top()<openclose.top()){
            open.pop();
            openclose.pop();
        }
        if(open.size()==0){
            return true;
        }
        return false;
    
    }
};