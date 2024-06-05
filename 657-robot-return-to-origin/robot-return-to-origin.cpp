class Solution {
public:
    bool judgeCircle(string moves) {
        pair<int,int> p;
        p.first =0;
        p.second = 0;
        for(int i=0;i<moves.size();i++){
            if(moves[i]=='U'){
                p.second++;
            }
            if(moves[i]=='D'){
                p.second--;
            }
            if(moves[i]=='R'){
                p.first++;
            }
            if(moves[i]=='L'){
                p.first--;
            }
        }
        if(p.first==0 && p.second==0){
            return true;
        }
        return false;
    }
};