class Solution {
public:
    bool checkPowersOfThree(int n) {
        while(true){
            if(n==1) return true;
            int r = n%3;
            if(r==2)return false;
            n = n/3;
        }
        return false;
    }
};