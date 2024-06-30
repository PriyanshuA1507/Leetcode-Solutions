class Solution {
public:
    int count(int a, int b) {
        int h = 1;
        bool a1 = true;
        bool b1 = false;
        
        while (true) {
            if (a1 && a - h >= 0) {
                a -= h;
                a1 = false;
                b1 = true;
            } else if (b1 && b - h >= 0) {
                b -= h;
                b1 = false;
                a1 = true;
            } else {
                break;
            }
            h++;
        }
        
        return h - 1;
    }

    int maxHeightOfTriangle(int red, int blue) {
        return max(count(red, blue), count(blue, red));
    }
};
