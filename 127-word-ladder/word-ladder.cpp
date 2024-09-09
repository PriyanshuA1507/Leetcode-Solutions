class Solution {
public:
    // Function to generate all possible words by changing one character
    std::vector<std::string> getNextWords(const std::string& word, const std::unordered_set<std::string>& wordSet) {
        std::vector<std::string> nextWords;
        std::string tempWord = word;
        for (int i = 0; i < word.size(); ++i) {
            char originalChar = tempWord[i];
            for (char c = 'a'; c <= 'z'; ++c) {
                if (c == originalChar) continue;
                tempWord[i] = c;
                if (wordSet.find(tempWord) != wordSet.end()) {
                    nextWords.push_back(tempWord);
                }
            }
            tempWord[i] = originalChar;  // Restore original character
        }
        return nextWords;
    }
    
    int ladderLength(std::string beginWord, std::string endWord, std::vector<std::string>& wordList) {
        std::unordered_set<std::string> wordSet(wordList.begin(), wordList.end());
        
        // Edge case: If endWord is not in wordList, return 0
        if (wordSet.find(endWord) == wordSet.end()) {
            return 0;
        }
        
        std::queue<std::string> que;
        que.push(beginWord);
        int level = 1;
        
        while (!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; ++i) {
                std::string word = que.front();
                que.pop();
                
                if (word == endWord) {
                    return level;
                }
                
                // Generate all possible next words
                std::vector<std::string> nextWords = getNextWords(word, wordSet);
                for (const std::string& nextWord : nextWords) {
                    wordSet.erase(nextWord);  // Mark this word as visited
                    que.push(nextWord);
                }
            }
            ++level;
        }
        
        return 0;
    }
};
