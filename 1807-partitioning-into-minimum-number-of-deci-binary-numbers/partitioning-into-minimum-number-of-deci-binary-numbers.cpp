class Solution {
public:
    int minPartitions(string n) {
        
        int max = -1;
        for(int i=0;i<n.size();i++){
            if(max<(n[i]-'0')){
           max = n[i]-'0';
            }
        }

       return max;
    }
};