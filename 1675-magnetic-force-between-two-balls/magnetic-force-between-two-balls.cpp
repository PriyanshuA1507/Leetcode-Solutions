class Solution {
public:
    bool ip(vector<int>& position, int m, int mid) {
        int mc = 1; // count of markers placed
        int lastpos = position[0];
        
        for (int i = 1; i < position.size(); i++) {
            if (position[i] - lastpos >= mid) {
                mc++;
                if (mc == m) {
                    return true;
                }
                lastpos = position[i];
            }
        }
        return false;
    }
    
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int n = position.size();
        int s = 0;
        int e = position[n-1] - position[0]; // maximum possible distance
        int ans = 0;
        int mid;
        
        while (s <= e) {
            mid = s + (e - s) / 2;
            if (ip(position, m, mid)) {
                ans = mid;
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }
        
        return ans;
    }
};
