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
typedef long double ld;

const int MAXN = 100001;
const int mod = 1000000007;

pair<int,int> a[MAXN];
vector<pair<int,int> > tree[4*MAXN];
int n;
bool comp(const pair<int , int> &p1 , const pair<int,int> &p2 ){
    return p1.second < p2.second;
}

void build(int ss , int se , int si){
    if(ss == se){tree[si].push_back(a[ss]); return;}
    int mid = (ss + se)>>1;
    build(ss , mid , 2*si); build(mid+1 , se , 2*si+1);
    tree[si].resize(tree[2*si].size() + tree[2*si+1].size());
    merge(tree[2*si].begin(),tree[2*si].end() , tree[2*si+1].begin() , tree[2*si+1].end() ,tree[si].begin());
}

int query(int i , int j , int k , int si , int ss , int se){
    if(ss == se)return a[ss].second;
    int l = lower_bound(tree[2*si].begin() , tree[2*si].end() , make_pair(i , -mod)) - tree[2*si].begin();
    int r = upper_bound(tree[2*si].begin() , tree[2*si].end() , make_pair(j , mod)) - tree[2*si].begin();
    int mid = (ss + se)>>1;
    if(r-l < k)return query(i , j , k - (r-l) , 2*si+1 , mid+1 , se);
    else return query(i , j , k , 2*si , ss , mid);
}

int main(){
    inp_out_work

    int m;
    cin>>n>>m;
    fr(i,n){
        a[i].first = i+1;
        cin>>a[i].second;
    }

    sort(a , a + n , comp);

    build(0 , n-1 , 1);

    while(m--){
        int i , j , k;
        cin>>i>>j>>k;
        cout<< query(i , j , k , 1 , 0 , n-1) << endl;
    }


}
