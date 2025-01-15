class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    queue<string> q;
     unordered_map<string,bool> m;
     for(auto a:wordList){
      m[a]= true;
     }
     if(!m[endWord]){
        return 0;
     }
     unordered_map<string,bool> visit;
     int ans = 1;
     q.push(beginWord);
     visit[beginWord] = true;

     while(q.size()!=0){
     int a = q.size();
     for(int i=0;i<a;i++){
     auto b = q.front();
     q.pop();
     if(b==endWord){
        return ans;
     }
     for (int j = 0; j < b.size(); j++) {
                    string temp = b;
                    for (char c = 'a'; c <= 'z'; c++) {
                        temp[j] = c;
                        if (m[temp] && !visit[temp]) {
                            visit[temp] = true; 
                            q.push(temp);
                        }
                    }
                }
     }
      ans++;
     }
     return 0;  
    }
};