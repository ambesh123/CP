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

const int MAXN = 100001;
const int mod = 1000000007;

int cur;
int lazy[3][4*MAXN];

int query_util(int *st,int ss,int se,int si,int l,int r){
    if(ss>r || l>se)return 0;

    if(lazy[cur][si]){
            st[si] = (se - ss + 1)*lazy[cur][si] + st[si];
            if(ss!=se){
                lazy[cur][2*si+1] += lazy[cur][si] ;
                lazy[cur][2*si+2] += lazy[cur][si] ;
            }
            lazy[cur][si] = 0;
    }

    if(ss>=l && se<=r)return st[si];

    int mid = (ss+se)>>1;
    return query_util(st,ss,mid,2*si+1,l,r)  + query_util(st,mid+1,se,2*si+2,l,r);
}

int query(int *st,int n, int l , int r){
    return query_util(st,0,n-1,0,l,r);
}

int update_util(int *st,int ss,int se,int si,int l,int r, int v){
    if(lazy[cur][si]){
            st[si] = (se - ss + 1)*lazy[cur][si] + st[si];
            if(ss!=se){
                lazy[cur][2*si+1] += lazy[cur][si] ;
                lazy[cur][2*si+2] += lazy[cur][si] ;
            }
            lazy[cur][si] = 0;
    }

    if(ss>r || se<l)return st[si];

    if(ss==se){
        st[si] = v + st[si];
        return st[si];
    }
    if(ss>=l && se<=r){
            st[si] = (se - ss + 1)*v + st[si];
            lazy[cur][2*si+1] = v + lazy[cur][2*si+1] ;
            lazy[cur][2*si+2] = v + lazy[cur][2*si+2];
            return st[si];
    }
    int mid = (ss + se)>>1;
    return st[si] = update_util(st,ss,mid,2*si+1,l,r,v)  + update_util(st,mid+1,se,2*si+2,l,r,v);
}

void update(int *st,int n ,int l,int r, int v){
    update_util(st,0,n-1,0,l,r,v);
}



int main(){
   //inp_out_work
   int n;
   cin>>n;
   int a[n];
   fr(i,n)cin>>a[i];

   int sz = pow(2,ceil(log2(n))+1) - 1;
   int *st2 = new int[sz];
   int *st3 = new int[sz];
   int *st5 = new int[sz];
   fill(st2,st2+sz,0);
   fill(st3,st3+sz,0);
   fill(st5,st5+sz,0);

   int m;
   cin>>m;
   while(m--){
    int t , l , r, p;
    cin>>t;
    if(t == 1){
        cin>>l>>r>>p;
        l-- , r--;
        switch(p){
            case 2: cur = 0; update(st2 , n , l , r , 1); break;
            case 3: cur = 1; update(st3 , n , l , r , 1); break;
            case 5: cur = 2; update(st5 , n , l , r , 1);
        }
    }
    else{
        cin>>l>>p;
        l--;
        a[l] = p;

        cur = 0;
        update(st2 , n , l , l , -query(st2 , n , l , l));
        cur = 1;
        update(st3 , n , l , l , -query(st3 , n , l , l));
        cur = 2;
        update(st5 , n , l , l , -query(st5 , n , l , l));
    }
   }
   for(int i = 0; i < n; i++){
    cur = 0;
    int x2 = query(st2 , n , i , i);
    cur = 1;
    int x3 = query(st3 , n , i , i);
    cur = 2;
    int x5 = query(st5 , n , i , i);


    while(x2 > 0 && a[i]%2 == 0){
        x2--; a[i] >>= 1;
    }
    while(x3 > 0 && a[i]%3 == 0){
        x3-- , a[i] /= 3;
    }
    while(x5 > 0 && a[i]%5 == 0){
        x5-- , a[i] /= 5;
    }
    cout<< a[i] << ' ';
   }
   cout<< endl;
}
