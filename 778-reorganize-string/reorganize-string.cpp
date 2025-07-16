class Solution {
public:
    string reorganizeString(string s) {
    unordered_map<char,int>m;
    for(int i=0;i<s.size();i++){
     m[s[i]]++;
    }
    priority_queue<pair<int,char>> pq;
    for(auto a:m){
     pq.push({a.second,a.first});
    }
    string ans = "";
    while(pq.size()!=0){
     bool op = false;
     auto a1 = pq.top();
     int count1 = a1.first;
     pq.pop();
     if(ans.size()==0 || ans.back()!=a1.second){
      ans.push_back(a1.second);
      char s2 = a1.second;
      count1--;
       if (count1 > 0) {
       pq.push({count1, s2});
     }
      op = true;
     }
     else  if(ans.back() == a1.second && pq.size()>0){
     auto b2 = pq.top();
     pq.pop();
     ans.push_back(b2.second);
      char s1 = b2.second;
      int count2 = b2.first;
      count2--;
      if(count2>0){
      pq.push({count2,s1});
      }
      if(count1>0){
       pq.push({count1,a1.second}); 
      }
      op = true;
     }
     else if(!op){
        return "";
     }
    }
    return ans;
    }
};