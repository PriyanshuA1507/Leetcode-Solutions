class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
       int n = A.size();
        vector<int> c(n,0);
        vector<int> f(n+1,0);
        int count=0;
       for(int i=0;i<n;i++){
           f[A[i]]++;
           if(f[A[i]]==2) count++;
            f[B[i]]++;
           if(f[B[i]]==2) count++;
            c[i]=count;
       }
       return c;    
    }
};