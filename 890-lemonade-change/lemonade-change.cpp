class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int,int>m;
        for(auto a:bills){
        if(a==5){
        m[a]++;
        }
        else if(a==10){
         if(m[5]<=0){
          return false;
         }
         m[5]--;
         m[10]++;
        }
         else if(a==20){
         if(m[10]>0 && m[5]>0){
            m[5]--;
            m[10]--;
         }
         else if(m[5]>=3){
            m[5]--;
             m[5]--;
              m[5]--; 
         }
         else {
                    return false;
                }
        }
        }
        return true;

    }
};