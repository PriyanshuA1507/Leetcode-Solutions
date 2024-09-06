class Solution {
public:
    int nextGreaterElement(int n) {
        string a = to_string(n);
     
        if (!next_permutation(a.begin(), a.end())) {
            return -1; 
        }

      
        long long z = stoll(a);  
        
        if (z > INT_MAX) {
            return -1;
        }
        
        return static_cast<int>(z);
    }
};