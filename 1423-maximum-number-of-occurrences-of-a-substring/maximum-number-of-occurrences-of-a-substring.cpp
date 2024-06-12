class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
    int maxans=0;
    unordered_map<char,int> m1;
    unordered_map<string,int> m2;
    int start=0;
    int end =0;
    while(end<s.size()){
      m1[s[end]]++;
    if(end-start+1>minSize || m1.size()>maxLetters){
      m1[s[start]]--;
      if(m1[s[start]]==0){m1.erase(s[start]);}
      start++;
    }
    if(end-start+1==minSize && end-start+1<=maxSize && m1.size()<=maxLetters){
        maxans = max(maxans, ++m2[s.substr(start,minSize)]);
    }
    end++;
    }
    return maxans;
    }
};