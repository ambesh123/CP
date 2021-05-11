const int MAXN = 1000001;
const int mod = 1e9 + 7;
 
ll fac[MAXN];
ll finv[MAXN];
 
ll modPower(ll x, ll y) {
    x %= mod;
    ll res = 1;
    while(y) {
        if(y&1) res = res*x % mod;
        x = x*x % mod;
        y >>= 1;
    }
    return res;
}
 
void ini() {
    fac[0] = 1;
    for(int i = 1; i < MAXN; ++i) {
        fac[i] = fac[i-1] * i % mod;
    }
    finv[MAXN-1] = modPower(fac[MAXN-1], mod-2);
    for(int i = MAXN-2; i >= 0; --i) {
        finv[i] = finv[i+1] * (i+1) % mod;
    }
}
 
ll nCr(int n, int r) {
    if(r > n) return 0;
    return (fac[n] * finv[r]%mod) * finv[n-r] % mod;
}
