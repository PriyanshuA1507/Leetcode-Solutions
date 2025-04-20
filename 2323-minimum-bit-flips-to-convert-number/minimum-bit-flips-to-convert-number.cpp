class Solution {
public:
    int minBitFlips(int start, int goal) {
      int cnt = 0;
      int a = start^goal;
      while(a!=0){
        a = a&(a-1);
        cnt++;
      }
      return cnt;
    }
};