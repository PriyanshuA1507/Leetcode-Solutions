class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    
  map<char,int> m;
  int start=0;
  int end = 0;
  int ans =0;
  while(end<s.size()){
    m[s[end]]++;
    if(m.size()>end-start+1){
        end++;
    }
    else if(m.size()==end-start+1){
        ans = max(ans,end-start+1);
        end++;
    }
    else if(m.size()<end-start+1){
    while(m.size()<end-start+1){
        m[s[start]]--;
        if(m[s[start]]==0){
          m.erase(s[start]);  
        }
        start++;
    }
    end++;
    }
  }
  return ans;
    }
};
