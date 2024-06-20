class Solution {
public:
    int minTimeToType(string word) {
        int ans = 0;
        int start = (int)'a';
        for(int i=0;i<word.size();i++){
            int curr = int(word[i]);
            ans += min(abs(start-curr), 26 - abs(start-curr));
            start = curr;
        }
        int size = word.size();
        return ans + size;
    }
};