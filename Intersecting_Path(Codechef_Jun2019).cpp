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
//typedef long double ld;

const int MAXN = 300001;
const int mod = 1000000007;


const int ML = 20;

vector< int > adj[MAXN];
int lvl[MAXN];
int par[MAXN][ML];
ll in[MAXN];
ll cnt[MAXN];
ll sum[MAXN][ML];

int n;

void ini(){
    fr(i,MAXN)adj[i].clear();
}

void dfs1(int x){
    in[x] = 1;
    for(int c : adj[x]){
        if(c != par[x][0]){
            par[c][0] = x;
            lvl[c] = lvl[x] + 1;
            dfs1(c);
            in[x] += in[c];
        }
    }
    cnt[x] = 0;
    for(int c : adj[x]){
        if(c != par[x][0]){
            cnt[x] += (in[x] - in[c]-1) * in[c];
        }
    }
    cnt[x] >>= 1;
    cnt[x] += in[x];
}



void pre(){
    lvl[0] = -1;
    fro(x,1,n){
        sum[x][0] = cnt[par[x][0]] - (in[par[x][0]] - in[x])*in[x];
    }
    for(int l = 1; l < ML; l++){
        for(int i = 1; i <= n; i++){
            par[i][l] = par[par[i][l-1]][l-1];
            sum[i][l] = sum[par[i][l-1]][l-1] + sum[i][l-1];
        }
    }
}

int lca(int x , int y){
    if(lvl[x] < lvl[y])swap(x,y);

    for(int l = ML-1; l >= 0; l--){
        if(lvl[par[x][l]] >= lvl[y])x = par[x][l];
    }

    if(x == y)return x;

    for(int l = ML-1; l >= 0; l--){
        if(par[x][l] != par[y][l]){
            x = par[x][l];
            y = par[y][l];
        }
    }

    return par[x][0];

}

ll query(int x , int y){
    if(x == y){
        return (n- in[x]) * in[x] + cnt[x];
    }
    if(lvl[x] < lvl[y])swap(x,y);

    int tx = x;
    ll sm = cnt[x];

    for(int l = ML-1; l >= 0; l--){
        if(lvl[par[x][l]] >= lvl[y]){
                sm += sum[x][l];
                x = par[x][l];
        }
    }

    if(x == y){
            for(int l = ML-1; l >= 0; l--){
                if(lvl[par[tx][l]] > lvl[y]){
                        tx = par[tx][l];
                }
            }
            sm += (n - in[y]) * (in[y] - in[tx]);
            return sm;
    }

    sm += cnt[y];

    for(int l = ML-1; l >= 0; l--){
        if(par[x][l] != par[y][l]){
            sm += sum[x][l];
            sm += sum[y][l];
            x = par[x][l];
            y = par[y][l];
        }
    }
    int L = par[x][0];
    sm += cnt[L] - in[x] * in[y] - (in[L] - in[x] - in[y])*(in[x] + in[y]);
    sm += (n - in[L]) * (in[L] - in[x] - in[y]);

    return sm;

}


int main(){
   FILE
   //inp_out_work
    testCase{
        ini();
        int q;
        cin>>n>>q;
        fr(i,n-1){
            int u , v;
            cin>>u>>v;
            adj[u].pb(v);
            adj[v].pb(u);
        }

        dfs1(1);
        pre();
   // cout<<"sum and cnt\n"; fro(i , 1 , n)cout<< sum[i][0] <<' '<<cnt[i] << endl; cout<<"end\n";
        while(q--){
            int u , v;
            cin>>u>>v;
            cout<< query(u , v) << endl;
        }
    }
}
