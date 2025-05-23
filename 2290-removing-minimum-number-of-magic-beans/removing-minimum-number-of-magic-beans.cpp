class Solution {
public:
 using ll = long long;
    long long minimumRemoval(vector<int>& beans) {
    int n = beans.size();
    if(n==1){
    return 0;
    }
    sort(beans.begin(),beans.end());
    vector<ll> ps(n,0),ss(n,0);
    ps[0] = beans[0];
    ss[n-1] = beans[n-1];
    for(int i=1;i<n;i++){
    ps[i] = ps[i-1] + beans[i];
    }
    for(int i=n-2;i>=0;i--){
    ss[i] = ss[i+1] + beans[i];
    }

    ll ans = LLONG_MAX;
    for(int i=1;i<n-1;i++){
    ll ans2 = ps[i-1] + abs((1LL * beans[i] * (n - (i + 1))) - ss[i+1]);
     ans = min(ans2,ans);
    }
    ll c1 = abs(1LL * beans[0] * (n - 1) - ss[1]);
    ll c2 = ps[n-2];

    ans = min({ans,c1,c2});

    return ans;
    }
};