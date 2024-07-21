class Solution {
public:
    bool doesAliceWin(string s) {
     
     bool a = true;
     bool b = false;
     int c=0;
     for(int i=0;i<s.size();){
        if(a ){    
        
         if((s[i]=='a' ||s[i]=='i'||s[i]=='e'||s[i]=='o'||s[i]=='u')&& c<1){
        c++;
        i++;
        a = false;
        b = true;
        c=0;
         break;
         }
         else{
            i++;
         }   
        }
        else if(b){    
          if( c==2){
         a = true;
         b = false;
         c=0;
            break;
         }
         if((s[i]=='a' ||s[i]=='i'||s[i]=='e'||s[i]=='o'||s[i]=='u')&& c<2){
            c++;
            i++;
         }
         else{
            i++;
         }   
        }
     }
     if(a){
        return false;
     }
     return true;
    }
};