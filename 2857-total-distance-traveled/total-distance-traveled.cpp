class Solution {
public:
    int distanceTraveled(int mt, int at) {
        int ans = 0;

        while (mt >= 5) {
            ans += 50;
            if(at) at--,mt++;
            mt-=5;
        }

      
        ans += mt * 10;

        return ans;
    }
};
