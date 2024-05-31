class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
    unordered_set<int> m(arr.begin(), arr.end()); 
        int i = 1; 
        while (k > 0) {
            if (m.find(i) == m.end()) { 
                k--; 
            }
            if (k > 0) {
                i++; 
            }
        }
        return i;
    }
};