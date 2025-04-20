class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
       unordered_map<char,int> m;
       for(auto a:t){
        m[a]++;
       } 
       int minstart = 0;
       int minwindow = INT_MAX;
       int requiredcount = t.size();
       int left = 0, right = 0;
       while(right<n){
      char ch_j = s[right];
      if(m[s[right]]>0){
        requiredcount--;
      }
      m[ch_j]--;
      while(requiredcount == 0){
    if(minwindow>right-left+1){
    minwindow = right-left + 1;
    minstart = left;
    }
    char ch_i = s[left];
    m[ch_i]++;
    if(m[ch_i]>0){
    requiredcount++;
    }
    left++;
      }
      right++;
       }
       return minwindow == INT_MAX?"":s.substr(minstart,minwindow);
    }
};