class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int gs) {
       if (hand.size() % gs != 0) {
            return false;
        }
        
        unordered_map<int, int> m;
        for (int card : hand) {
            m[card]++;
        }
        
        sort(hand.begin(), hand.end());
        
        for (int card : hand) {
            if (m[card] > 0) {
                for (int i = 0; i < gs; ++i) {
                    if (m[card + i] > 0) {
                        m[card + i]--;
                    } else {
                        return false;
                    }
                }
            }
        }
        
        return true;
    }
};