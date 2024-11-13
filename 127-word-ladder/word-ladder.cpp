class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    queue<pair<string,int>> q;
    q.push({beginWord,0});
    unordered_set s(wordList.begin() , wordList.end());
    s.erase(beginWord);
    while(q.size()!=0){
    string word = q.front().first;
    int dist = q.front().second;
    q.pop();
    if(word==endWord){
        return dist+1;
    }
    for(int i=0;i<word.size();i++){
     char originalchar = word[i];
     for(char ch='a';ch<='z';ch++){
        word[i] = ch;
     if(s.find(word)!=s.end()){
        s.erase(word);
    q.push({word, dist+1});
     }
     }
     word[i] = originalchar;
    }
    }
    return 0;
    }
};