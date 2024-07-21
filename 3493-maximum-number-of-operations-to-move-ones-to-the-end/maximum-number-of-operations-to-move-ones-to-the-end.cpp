class Solution {
public:
    int maxOperations(string s) {
     reverse(s.begin(),s.end());
     int n = s.size();
     int si=n;
     for(int i=0;i<s.size();i++){
        if(s[i]=='0'){
            si=i;
            break;
        }
     }
      int ans=0,impact=1,j=-1;
     for(int i=si;i<n;i++){
        if(s[i]=='0')continue;
        int ct=0;
        for(j=i;j<n;j++){
        if(s[j]=='0')break;
        ct++;
        }
        ans+=ct*impact;
        impact++;
        i=j-1;
     }
    return ans;
    }
};