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


void create(int *st , vector<int> &a , int ss , int se , int si){
    if(ss == se){
        st[si] = a[ss];
        return;
    }
    int mid = (ss + se)>>1;
    create(st , a , ss , mid , 2*si+1);
    create(st , a , mid+1 , se , 2*si+2);
    st[si] = st[2*si+1] + st[2*si+2];
}

int *createST(vector<int> &a){
    int n = a.size();
    int sz = pow(2 , ceil(log2(n))+1) - 1;
    int *st = new int[sz];
    create(st , a , 0 , n-1 , 0);
    return st;
}



void update(int *st , int si , int ss , int se ,int idx , int add){
    if(idx > se || idx < ss)return;

    if(ss == se){
        st[si] += add;
        return;
    }

    int mid = (ss + se)>>1;

    update(st , 2*si + 1 , ss , mid , idx , add);
    update(st , 2*si + 2 , mid+1 , se , idx , add);

    st[si] = st[2*si+1] + st[2*si+2];
}

void updateST(int *st , int idx , int newValue , int n){
    int  oldValue = 1;
    int add = newValue - oldValue;
    update(st , 0 , 0 , n-1 , idx , add);
}

int query(int *st , int si , int ss , int se , int l , int r){
    if(ss >= l &&  se <= r)return st[si];
    if(se < l || ss > r)return 0;
    int mid = (ss + se)>>1;
    return query(st , 2*si+1 , ss , mid , l , r) + query(st , 2*si+2 , mid+1 , se , l , r);
}

int getIndex(int *st , int sum , int si , int ss , int se){
    if(ss == se)return ss;
    int mid = (ss + se)>>1;
    if(sum < st[2*si+1]){
        return getIndex(st , sum , 2*si+1 , ss , mid);
    }
    else{
        return getIndex(st , sum - st[2*si+1] , 2*si + 2 , mid+1 , se);
    }
}

vector<int> order(vector<int> &A, vector<int> &B) {
    int n = A.size();
    vector<pair<int,int> > h(n);
    for(int i = 0; i < n ; i++){
        h[i].first = A[i] , h[i].second = B[i];
    }
    sort(h.begin() , h.end());

    vector<int> a(n , 1);
    int *st = createST(a);

    for(int i = 0; i < n; i++){
        int x = getIndex(st , h[i].second, 0, 0, n-1) ;
        a[x] = h[i].first;
        updateST(st , x ,0 , n);
    }

    return a;

}

int main(){
   vector<int> A({66 , 42});
   vector<int> B({0, 1});
   vector<int> sol = order(A , B);
   for(int x : sol) cout<< x <<' ';
   return 0;
}
