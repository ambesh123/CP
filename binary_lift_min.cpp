                       //  @ /\/\ BESH //

//https://www.codechef.com/problems/POSTTREE
//Point to note : calculate first ancestor whose value is less than the node

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

const int MAXN = 200001;
const int mod = 1000000007;
const int LVL = 20;
const long inf = (long)(1e16);

int par[MAXN][LVL];
int depth[MAXN];
long a[MAXN];
long mn[MAXN][LVL];
long dp[MAXN];

int dep(int x){
  if(depth[x])return depth[x];
  if(x==1)return depth[x] = 1;
  return depth[x] = dep(par[x][0]) + 1;
}

void pre(int n){
  for(int l = 1; l< LVL; l++){
    for(int i = 1; i <= n; i++){
      par[i][l] = par[par[i][l-1]][l-1];
    }
  }

  for(int l = 1; l< LVL; l++){
    for(int i = 1; i <= n; i++){
      mn[i][l] = min(mn[i][l-1] , mn[par[i][l-1]][l-1]);
    }
  }

  for(int i= 1; i<=n; i++)dep(i);

  for(int i= 1; i<=n; i++)dp[i] = inf;
}

long cost(int x){
  if(dp[x] != inf)return dp[x];
  if(x == 1)return dp[x] = mn[x][0];

  int y = x;

  for(int l = LVL-1; l >= 0; l--){
    if(mn[y][l] >= mn[x][0]){
      y = par[y][l];
    }
  }
  
  return dp[x] = (depth[x] - depth[y])*(mn[x][0]) + cost(y);
}

int main(){
  int n;
  cin>>n;
  for(int i = 2; i<= n; i++)cin>>par[i][0];
  for(int i = 1; i<= n; i++)cin>>mn[i][0];

  pre(n);

  for(int i= 1; i<= n; i++){
    cout<< cost(i) <<' ';
  }
  cout<<endl;
}
