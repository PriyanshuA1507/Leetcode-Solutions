class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
      istringstream stream(sentence);
        vector<string> words;
        string word;
        while (stream >> word) {
            words.push_back(word);
        }
      int ans = -1;
      for(int i=words.size()-1;i>=0;i--){
        string a = words[i];
        bool a1 = true;
        for(int j=0;j<searchWord.size();j++){
            if(a[j]!=searchWord[j]){
                a1=false;
                break;
            }
        }
        if(a1){
            ans = i+1;
        }
      }
      return ans;  
    }
};