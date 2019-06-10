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
#define MAXN 10001

using namespace std;

vector<int> adj[MAXN];
int euler[2*MAXN];
int depth[MAXN+1];
int fa[MAXN];
int tree[4*MAXN];
int n,N;
int ptr = 0;

int mini(int x,int y){
    if(depth[x]>depth[y])return y;
    else return x;
}

void build_tree(){
    N = 2*n-1;
    fr(i,N)tree[N+i]=euler[i];
    for(int i=N-1;i>0;i--){
        tree[i] = mini(tree[i<<1],tree[i<<1 | 1]);
    }
}

int query(int l,int r){
    l+=N; r+=N;
    int res = MAXN;
    while(l<r){
        if(l&1)res = mini(res,tree[l++]);
        if(r&1)res = mini(res,tree[--r]);
        l>>=1; r>>=1;
    }
    return res;
}

void euler_walk(int src,int p,int dep){
    if(!fa[src])fa[src]=ptr;
    depth[src] = dep;
    euler[ptr++]=src;

    for(int e : adj[src]){
        if(e!=p){
            euler_walk(e,src,dep+1);
            euler[ptr++]=src;
        }
    }
}

int lca(int x,int y){
    int l = fa[x], r = fa[y];
    if(l>r)swap(l,r);
    return query(l,r+1);
}

int main(){
    cin>>n;
    int u,v;
    fr(i,n-1){
        cin>>u>>v;
        adj[u].pb(v); adj[v].pb(u);
    }
    depth[MAXN]=INT_MAX;
    euler_walk(1,0,0);
    build_tree();
    int q;
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        cout<<lca(l,r)<<endl;
    }
}
