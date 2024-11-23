class Solution {
public:
    bool canAliceWin(int n) {
     bool alice = true;
     bool bob = false;
     int turn = 10;
     while(n>=turn){
      n-=turn;
      turn--;
      alice = !alice;
      bob = !bob;
     }
     if(alice){
        return false;
     }
     return true;
    }
};