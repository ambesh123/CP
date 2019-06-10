					   //  @ /\/\ BESH //

#include <bits/stdc++.h>
#define inp_out_work ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define testCase    int T; cin>>T; while(T--)
#define fr(i,n) for(int i=0;i<n;i++)
#define fro(s,e) for(int i=s;i<=e;i++)
#define endl '\n'
#define ll long long
#define pb push_back
#define MAXN 100005
#define debug(P) cout<<#P<<' '<<P<<endl
#define mp make_pair
#define MOD 1000000007

using namespace std;

int arr[MAXN];
int n;

int maxi(int i1,int i2){
    if(arr[i1]>arr[i2])return i1;
    return i2;
}

int cst(int *st,int arr[],int ss,int se,int si){
    if(ss==se){st[si]=ss; return ss;}
    int mid = ss + ((se-ss)>>1);
    st[si] = maxi(cst(st,arr,ss,mid,2*si+1),cst(st,arr,mid+1,se,2*si+2));
    return st[si];
}

int *constructST(int arr[],int n){
    int sz = pow(2,ceil(log2(n))+1) -1;
    int *st;
    st = new int[sz];
    cst(st,arr,0,n-1,0);
    return st;
}

void udt(int *st,int ss,int se,int si,int idx){
    if(ss>idx || se<idx)return;
    if(ss==se){ return;}
    int mid = ss + ((se-ss)>>1);
    udt(st,ss,mid,2*si+1,idx); udt(st,mid+1,se,2*si+2,idx);
    st[si] = maxi(st[2*si+1],st[2*si+2]);
}

void update(int idx,int *st,int n){
    udt(st,0,n-1,0,idx);
}

int getMax(int *st,int qs,int qe,int ss,int se,int si){
    if(qs>se || qe<ss)return MAXN-1;
    if(qs<=ss && qe>=se)return st[si];
    int mid = ss + ((se-ss)>>1);
    return maxi(getMax(st,qs,qe,ss,mid,2*si+1),getMax(st,qs,qe,mid+1,se,2*si+2));
}

ll cstS(ll *st,int arr[],ll ss,ll se,ll si){
    if(ss==se){st[si]=arr[ss]; return st[si];}
    ll mid = ss + ((se-ss)>>1);
    st[si] = cstS(st,arr,ss,mid,2*si+1)+cstS(st,arr,mid+1,se,2*si+2);
    return st[si];
}

ll *constructSTS(int arr[],ll n){
    ll sz = pow(2,ceil(log2(n))+1) -1;
    ll *st;
    st = new ll[sz];
    cstS(st,arr,0,n-1,0);
    //fr(i,sz)cout<<st[i]<<' '; cout<<endl;
    return st;
}

void udtS(ll *st,ll ss,ll se,ll si,ll idx,ll val){
    if(ss>idx || se<idx)return;
    if(ss==se){ st[si]=val; return;}
    ll mid = ss + ((se-ss)>>1);
    udtS(st,ss,mid,2*si+1,idx,val); udtS(st,mid+1,se,2*si+2,idx,val);
    st[si] = st[2*si+1]+st[2*si+2];
}

void updateS(ll idx,ll val,ll *st,ll n){
    arr[idx]=val;
    udtS(st,0,n-1,0,idx,val);
}

ll getSum(ll *st,ll qs,ll qe,ll ss,ll se,ll si){
    if(qs>se || qe<ss)return 0;
    if(qs<=ss && qe>=se)return st[si];
    ll mid = ss + ((se-ss)>>1);
    return getSum(st,qs,qe,ss,mid,2*si+1)+getSum(st,qs,qe,mid+1,se,2*si+2);
}


int findSumEle(ll *st,ll sm,int ss,int se,int si){
    if(ss==se){
        return ss;
    }
    int mid = ss + ((se-ss)>>1);
    if(st[2*si+1]<sm){
        return findSumEle(st,sm-st[2*si+1],mid+1,se,2*si+2);
    }
    else{
        return findSumEle(st,sm,ss,mid,2*si+1);
    }
}


int main(){
    inp_out_work
    arr[MAXN-1]=INT_MIN;
    testCase{
        int Q,q,l,r;
        cin>>n>>Q;
        fr(i,n)cin>>arr[i];
        int *stM; ll *stS;
        stM = constructST(arr,n);
        stS = constructSTS(arr,n);
        while(Q--){
            cin>>q>>l>>r;
            l--; r--;
            if(q==1){
                ll mode,median;
                mode = getMax(stM,l,r,0,n-1,0) + 1;
                //debug(mode);
                ll sm = getSum(stS,l,r,0,n-1,0) + 1;
                sm>>=1;
                sm+= getSum(stS,0,l-1,0,n-1,0);
                median = findSumEle(stS,sm,0,n-1,0)+1;
                //debug(median);
                cout<< (mode*median)/__gcd(mode,median)<<endl;
            }
            else{
                updateS(l,r+1,stS,n);
                update(l,stM,n);
            }
        }
    }
}
