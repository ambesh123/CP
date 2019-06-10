#include <bits/stdc++.h>
#define inp_out_work ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define testCase    int T; cin>>T; while(T--)
#define fr(i,n) for(int i=0;i<n;i++)
#define rfr(i,n) for(int i=n-1;i>=0;i--)
#define fro(s,e) for(int i=s;i<=e;i++)
#define pb push_back
#define ll long long
#define MAXN 10000
#define mod 1000000007

using namespace std;

//HarryWand

int maxsticksUsed(int l[],int k,int wandL){
    int ms[wandL+1];    //ms[i] denotes maximum sticks required for creating a wand of length i
    fill(ms,ms+wandL+1,INT_MIN);
    ms[0]=0;
    fro(1,wandL){
        fr(j,k){
            if(l[j]<=i){
                ms[i] = max(ms[i],ms[i-l[j]]+1);
            }
        }
                //fr(j,wandL+1)cout<<ms[j]<<' '; cout<<endl;
    }
    if(ms[wandL]==INT_MIN+1)return -1;
    return ms[wandL];
}

int minsticksUsed(int l[],int k,int wandL){
    int ms[wandL+1];    //ms[i] denotes minimum sticks required for creating a wand of length i
    fill(ms,ms+wandL+1,INT_MAX-1);
    ms[0]=0;
    fro(1,wandL){
        fr(j,k){
            if(l[j]<=i){
                ms[i] = min(ms[i],ms[i-l[j]]+1);
            }
        }
                //fr(j,wandL+1)cout<<ms[j]<<' '; cout<<endl;
    }
    if(ms[wandL]==INT_MAX-1)return -1;
    return ms[wandL];
}


int main(){
    int n,k;
    cin>>n>>k;
    int a[k];
    fr(i,k)cin>>a[i];
    int minS=minsticksUsed(a,k,n);
    int maxS=maxsticksUsed(a,k,n);
    cout<<minS<<' '<<maxS;
}
