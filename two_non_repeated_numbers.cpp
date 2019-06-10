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
#define MAXN 100001

using namespace std;

//Program to find the only 2 elements which are not repeated 2 times

int main(){
    int n;
   // cin>>n;
    vector<int> v1= {1,1,2,4,5,3,8,5,8,4,11,2};  n = v1.size(); //     = > 11 and 3 are not repeated
    //fr(i,n)cin>>v1[i];
    vector<int> v2,v3;
    int x = 0;
    fr(i,n)x = v1[i]^x;
    int chk = 1;
    while((chk&x)==0){
        chk<<=1;
    }
    fr(i,n){
        if(v1[i]&chk){
            v2.pb(v1[i]);
        }
        else v3.pb(v1[i]);
    }
    int ans1=0,ans2 = 0;
    fr(i,v2.size())ans1^= v2[i];
    fr(i,v3.size())ans2^= v3[i];
    cout<<"Two numbers are : "<< ans1 <<' '<< ans2 << endl;
}
