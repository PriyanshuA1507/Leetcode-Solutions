class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int f = colors[0];
        int l = colors[colors.size()-1];
        int ans=0;
        for(int i=0;i<colors.size();i++){
          if(i==0){
            if(l!=colors[i] && colors[i]!=colors[i+1]){
                ans++;
            }
          }
          else if(i==colors.size()-1){
            if(colors[i-1]!=colors[i] && colors[i]!=f){
                ans++;
            }
          }
          else if( colors[i]!=colors[i-1] && colors[i]!=colors[i+1]){
            ans++;
          }
        }
        return ans;
    }
};