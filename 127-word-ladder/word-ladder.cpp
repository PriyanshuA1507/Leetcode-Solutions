class Solution {
public:
    vector<string> check(string word,unordered_set<string>& wordSet){
        vector<string> adjacentWords;
        string tempWord = word;
        for (int i = 0; i < word.size(); ++i) {
            char originalChar = tempWord[i];
            for (char c = 'a'; c <= 'z'; ++c) {
                if (c == originalChar) continue;
                tempWord[i] = c;
                if (wordSet.find(tempWord) != wordSet.end()) {
                    adjacentWords.push_back(tempWord);
                }
            }
            tempWord[i] = originalChar;  
        }
        return adjacentWords;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
       unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (wordSet.find(endWord) == wordSet.end()) {
            return 0;
        }
        queue<string> que;
        int level= 0 ;
        que.push(beginWord);
        while(que.size()!=0){
         int size = que.size();
         for(int i=0;i<size;i++){
            string a = que.front();
            que.pop();
            if(a==endWord){
                return level+1;
            }
            vector<string> b = check(a,wordSet);
            for(auto a1:b){
                wordSet.erase(a1);
                    que.push(a1);
            }
         }
         level++;
        }
        return 0;
    }
};