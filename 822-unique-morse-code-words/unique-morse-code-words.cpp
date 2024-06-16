class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
      vector<string> h = {".-","-...","-.-.","-..",".","..-.","--.","....","..",
                            ".---","-.-",".-..","--","-.","---",".--.","--.-",".-.",
                            "...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_set<string> uniqueTransformations;
        for (const string& word : words) {
            string morseCode = "";
            for (char c : word) {
                morseCode += h[c - 'a'];
            }
            uniqueTransformations.insert(morseCode);
        }
        return uniqueTransformations.size();
    }
};