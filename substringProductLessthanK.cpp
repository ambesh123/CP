#include <bits/stdc++.h>
#define inp_out_work ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define testCase    ll T; cin>>T; while(T--)
#define fr(i,n) for(ll i=0;i<n;i++)
#define rfr(i,n) for(ll i=n-1;i>=0;i--)
#define fro(s,e) for(ll i=s;i<=e;i++)
#define pb push_back
#define ll long long
#define MAXN 10000
#define mod 1000000007

using namespace std;


int main()
{   inp_out_work
    ll k;
    int n;
    testCase{
        cin>>n>>k;
        int a[n];
        fr(i,n)cin>>a[i];
        ll mul=1,ans=0;
        int left = 0;
        fr(i,n){
            mul*=a[i];
            while(mul>=k && left<=i ){
                mul/=a[left]; left++;
            }
            ans+=i+1-left;
        }
        cout<<ans<<'\n';
    }
}
