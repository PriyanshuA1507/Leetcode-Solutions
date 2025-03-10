class Solution {
public:
 long long atleastk(string word, long long k) {
     long long n = word.size();
        unordered_map<char, long long> vowelCount;
        long long consonantCount = 0;
        long long start = 0, end = 0, ans = 0;

        while (end < word.size()) {
            char ch = word[end];
            
            
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                vowelCount[ch]++;
            } else {
                consonantCount++;
            }
            
        
            while ( vowelCount.size() == 5 && consonantCount >= k ) {
                ans += n - end;
                char leftChar = word[start];
                
                if (leftChar == 'a' || leftChar == 'e' || leftChar == 'i' || leftChar == 'o' || leftChar == 'u') {
                    vowelCount[leftChar]--;
                    if (vowelCount[leftChar] == 0) {
                        vowelCount.erase(leftChar);
                    }
                } else {
                    consonantCount--;
                }
                
                start++;
            }
            end++;
        }
        
        return ans;
    }
    long long countOfSubstrings(string word, long long k) {
        return atleastk(word,k) - atleastk(word,k+1);
    }
};
