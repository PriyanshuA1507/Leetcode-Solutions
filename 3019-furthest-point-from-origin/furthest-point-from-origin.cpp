class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int ans = 0;
        int l=0, r=0;
        for(int i=0;i<moves.size();i++){
            if(moves[i]=='L'){
                l++;
            }
            if(moves[i]=='R'){
                r++;
            }
        }
        if(l>r){
        for(int i=0;i<moves.size();i++){
            if(moves[i]=='_' || moves[i]=='L'){
             ans++;
            }
            else{
                ans--;
            }
        }
        }
        if(r>=l){
        for(int i=0;i<moves.size();i++){
            if(moves[i]=='_' || moves[i]=='R'){
             ans++;
            }
            else{
                ans--;
            }
        }
        }
        return ans;     
    }
};