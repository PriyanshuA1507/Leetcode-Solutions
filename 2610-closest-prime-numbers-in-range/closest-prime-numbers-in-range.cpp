class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        if (right < 2) return {-1, -1};

        vector<int> prime(right + 1, 1);
        prime[0] = prime[1] = 0; 
        
     
        for (int i = 2; i * i <= right; i++) {
            if (prime[i]) {
                for (int j = i * i; j <= right; j += i) {
                    prime[j] = 0;
                }
            }
        }

        int prev = -1, minGap = INT_MAX;
        vector<int> result = {-1, -1};

        for (int i = left; i <= right; i++) {
            if (prime[i]) {
                if (prev != -1 && (i - prev) < minGap) {
                    minGap = i - prev;
                    result = {prev, i};
                }
                prev = i;
            }
        }
        
        return result;
    }
};