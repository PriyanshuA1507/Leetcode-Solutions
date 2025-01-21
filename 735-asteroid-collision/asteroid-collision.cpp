class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
     stack<int> s;
    for(int i=0;i<a.size();i++){
      bool ex = false;
    while(s.size()>0 && s.top()>0 && a[i]<0){
    if(s.top()+a[i]==0){
    s.pop();
    ex = true;
    break;
    }
    else if(s.top()+a[i]<0){
      s.pop();  
    }
    else{
        ex = true;
        break;
    }
    }
    if(!ex){
        s.push(a[i]);
    }
    } 
    vector<int> ans;
    while(s.size()!=0){
    ans.push_back(s.top());
    s.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};