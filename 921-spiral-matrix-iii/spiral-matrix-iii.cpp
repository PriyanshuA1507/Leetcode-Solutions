class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>>ans;
        int len=1;
        int x=rStart;
        int y=cStart;
        ans.push_back({x,y});
        if (rows*cols == 1) return ans;
        int dir=1;
        int right=2;
        while(ans.size()<rows*cols){
            int currlen=len;
            while(currlen>0){
                if(dir==1){
                    y++;
                }
                if(dir==-1){
                    y--;
                }
                if(dir==2){
                    x++;
                }
                if(dir==-2){
                    x--;
                }
                if(x>=0&&x<rows&&y<cols&&y>=0){
                    ans.push_back({x,y});
                }
                currlen--;
            }
            right--;
            if(right==0){
                right=2;
                len++;
            }
            if(dir==1){
                dir=2;
            }
            else if(dir==2){
                dir=-1;
            }
            else if(dir==-1){
                dir=-2;
            }
            else if(dir==-2){
                dir=1;
            }
        }
        return ans;
    }
};