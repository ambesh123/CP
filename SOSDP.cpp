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

const int MAXN = 1000001;
const int mod = 1000000007;

ll x[1<<17];    // superset
ll y[1<<17];    // subset

int main(){
    inp_out_work
    testCase{
        int n;
        cin>>n;
        int tn = 1<<n;

        fr(i,tn){
            cin>>x[i];
        }

        fr(i,tn){
            x[i] = (x[i]*i)%mod;
            y[i] = x[i];
        }

        for(int i = 0; i < n; i++){
            for(int mask = 0; mask < tn ; mask++){
                if((mask>>i)&1){
                   y[mask] = (y[mask] + y[mask^(1<<i)])%mod;
                }
                else{
                    x[mask] = (x[mask] + x[mask^(1<<i)])%mod;
                }
            }
        }


        int q;
        cin>>q;
        while(q--){
            int i , k;
            cin>>i>>k;
            if(k == 1)cout<< x[i]<<endl;
            else cout<<y[i] << endl;
        }

    }
}
