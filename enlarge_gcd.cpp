#include <bits/stdc++.h>
#define inp_out_work ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define testCase    int T; cin>>T; while(T--)
#define fr(i,n) for(int i=0;i<n;i++)
#define rfr(i,n) for(int i=n-1;i>=0;i--)
#define fro(i,s,e) for(int i=s;i<=e;i++)
#define pb push_back
#define ll long long
#define debug(P) cout<<#P<<' '<<P<<endl
#define endl '\n'
#define mod 1000000007
#define MAXN 1500001
//Remove minimum elements to enlarge gcd of all elements
using namespace std;

int cnt[MAXN];
bool b[MAXN];

int main(){
    int n;
    cin>>n;
    int a[n];
    int mxn = 0;
    fr(i,n)cin>>a[i];
    int g = 0;
    fr(i,n)g = __gcd(g,a[i]) , mxn = max(mxn,a[i]);
    bool same = true;
    fr(i,n)if(g!=a[i])same = false;
    if(same){
        cout<<"-1\n"; return 0;
    }
    fr(i,n)cnt[a[i]]++;
    int ans = 0;
    fro(i,g+1,mxn){
        if(!b[i]){ int tmp = 0;
           for(int j=i;j<=mxn;j+=i) {
                tmp+= cnt[j]; b[j] = 1;
            }
            ans = max(ans,tmp);
        }
    }
    ans = n-ans;
    cout<< ans<<endl;
}
