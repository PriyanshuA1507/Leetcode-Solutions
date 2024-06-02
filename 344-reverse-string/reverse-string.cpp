class Solution {
public:

  void reverseString(vector<char>& s, int i, int j){
      if(i>j) return;

      swap(s[i],s[j]);
      i++;j--;

      reverseString(s,i,j);
  }



    void reverseString(vector<char>& s) {
       
       reverseString(s,0,s.size()-1);
      
    }
};