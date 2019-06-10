                       //  @ /\/\ BESH //

#include <bits/stdc++.h>
#define inp_out_work ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define testCase    int T; cin>>T; while(T--)
#define fr(i,n) for(int i=0;i<n;i++)
#define fro(i,s,e) for(int i=s;i<=e;i++)
#define endl '\n'
#define debug(P) cout<<#P<<" = "<<P<<endl;
#define pb push_back
#define FILE freopen("in.txt","r",stdin); freopen("out.txt","w",stdout);


using namespace std;

typedef long long ll;

const int MAXN = 100001;
const int mod = 1000000007;


vector<long> primes;
bool prime[MAXN];

void sieve(){
    fr(i,MAXN)prime[i]=true;
    prime[0]=prime[1]=false;
    for(int i=2;i*i<MAXN;i++){
        for(int j=2*i;j<MAXN;j+=i)prime[j]=false;
    }
    fr(i,MAXN)if(prime[i])primes.pb(i);
}

void generatePrimes(int n , int m){
    int sz = m-n+1;
    bool p[sz];
    fill(p , p + sz , 1);
    for(int i = 0; primes[i]*primes[i] <= m; i++){
        int low = (primes[i] - (n%primes[i]))%primes[i];
        if(low == primes[i]-n) low += primes[i];
        while(low < sz)p[low] = 0 , low += primes[i];
    }
    if(n == 1)p[0] = 0;
    for(int i = 0; i < sz; i++)if(p[i]) cout<< n + i <<endl;
}

int main()
{
  sieve();
  testCase{
    int n , m;
    cin>>n>>m;
    generatePrimes(n , m);
  }
}
