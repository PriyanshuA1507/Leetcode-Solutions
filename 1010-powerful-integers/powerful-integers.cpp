class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
    set<int> a;
    for(int i=0;pow(x,i)<=bound;i++){
    for(int j=0;pow(y,j)<=bound;j++){
        long long sum = pow(x,i)+pow(y,j);
        if(sum<=bound){
            a.insert(sum);
        }
        if(y==1){break;}
    }
    if(x==1){break;}
    }
    vector<int> r(a.begin(),a.end());
    return r;
    }
};