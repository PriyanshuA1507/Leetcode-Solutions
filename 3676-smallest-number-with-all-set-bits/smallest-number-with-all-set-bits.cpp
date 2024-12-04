class Solution {
public:
    bool check(int n){
     vector<int> bn;
     while(n>0){
        bn.push_back(n%2);
        n = n/2;
     }
     for(int a:bn){
        if(a!=1){
            return false;
        }
     }
     return true;
    }
    int smallestNumber(int n) {
        bool found = false;
        int a = n;
        while(!found){
         if(check(a)){
            found = true;
            break;
         }
         else{
            a++;
         }
        }
        return a;
    }
};