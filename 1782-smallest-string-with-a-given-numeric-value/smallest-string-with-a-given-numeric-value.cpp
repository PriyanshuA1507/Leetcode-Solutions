class Solution {
public:
    string getSmallestString(int n, int k) {
        vector<char> a(n,'a');
        int j=1;
        for(int i=n-1;i>=0;i--){
            if(26<=k-(n-j)){
                a[i]='z';
                k-=26;
                j++;
            }
            else if(26>(k-(n-j))){
               a[i] +=(k-(n-j))-1;
               k-=(k-(n-j));
               j++;
            }
        }
        string a1;
        for(int i=0;i<a.size();i++){
            a1.push_back(a[i]);
        }
        return a1;
    }
};