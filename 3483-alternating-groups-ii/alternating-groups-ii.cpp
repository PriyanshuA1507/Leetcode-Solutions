class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int ans =0;
        int c= 0;
        int n = colors.size();
       vector<int> a(colors.size()+k-1);
       for(int i=0;i<a.size();i++){
        a[i] = colors[i%n];
       }
       for(int i=1;i<a.size();i++){
        if(a[i]==a[i-1]){
         c=i;
        }
        if(i-c+1>=k){
            ans++;
        }
       }
       return ans;
    }
};
    