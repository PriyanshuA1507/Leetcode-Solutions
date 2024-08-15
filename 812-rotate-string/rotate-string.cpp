class Solution {
public:
    bool rotateString(string s, string goal) {
      if (s.size() != goal.size()) {
            return false;
        }

        
        string doubled_s = s + s;

        return doubled_s.find(goal) != string::npos;   
    }
};