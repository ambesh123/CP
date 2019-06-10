#include <bits/stdc++.h>
#define inp_out_work ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define testCase    int T; cin>>T; while(T--)
#define fr(i,n) for(int i=0;i<n;i++)
#define rfr(i,n) for(int i=n-1;i>=0;i--)
#define fro(i,s,e) for(int i=s;i<=e;i++)
#define pb push_back
#define debug(P) cout<<#P<<' '<<P<<endl
#define endl '\n'
#define mod 1000000007

using namespace std;

typedef long long ll;


const int MAXN = 100001;

// A program to remove 'hard' subsequences from given string with min cost


int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    ll A[n];    // cost of each letter
    fr(i,n)cin>>A[i];
    ll h = 0 , a = 0 , r = 0, d = 0;
    fr(i,n){
        switch(s[i]){
            case 'h' : h += A[i];
            break;
            case 'a' : a = min(h , a + A[i]);
            break;
            case 'r' : r = min( a , r + A[i]);
            break;
            case 'd' : d = min( r , d + A[i]);
        }
    }
    cout<< d << endl;
}
