class Solution {
public:

    vector<long long> checkprime(int n){
        vector<bool>isprime(n+1,true);
        vector<long long>primes;
        isprime[0]=isprime[1]=false;
        for(int i=2;i*i<=n;i++){
            if(isprime[i]==true){
                for(int j=i*i;j<=n;j+=i){
                    isprime[j]=false;
                }
            }
        }
        for(int i=2;i<=n;i++){
            if(isprime[i]==true){
                primes.push_back((long long)i*i);
            }
        }
        return primes;
    }
    int nonSpecialCount(int l, int r) {
        vector<long long>primes=checkprime(sqrt(r));
        int special=0;
        int total=r-l+1;
        for(auto i:primes){
            cout<<i<<" ";
        }
        cout<<endl;
        int left=lower_bound(primes.begin(),primes.end(),l)-primes.begin()-1;
        int right=upper_bound(primes.begin(),primes.end(),r)-primes.begin()-1;
        if(right<0||primes[right]<l){
            right=-1;
        }
        cout<<left<<" "<<right<<endl;

        if(right==-1){
            return total;
        }
        // if(left==-1){
        //     return total-(right+1);
        // }
        return total-(right-left);

    }
};