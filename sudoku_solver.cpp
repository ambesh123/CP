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
#define MAXN 100002
//#pragma GCC optimise("O1")

using namespace std;

int a[9][9];

bool col_check(int a[9][9],int n,int c){
    fr(i,9)if(a[i][c]==n)return false;
    return true;
}
bool row_check(int a[9][9],int n,int r){
    fr(i,9)if(a[r][i]==n)return false;
    return true;
}

bool grid_check(int a[9][9],int n,int r,int c){
    r = (r/3);
    r*= 3;
    c = (c/3);
    c*= 3;
    for(int i=r;i<r+3;i++)
        for(int j=c;j<c+3;j++)if(a[i][j]==n)return false;

    return true;
}

bool filled(int a[9][9]){
    fr(i,9)fr(j,9){
        if(a[i][j]==0)return false;
    }
    return true;
}

void print(int a[9][9]){
    cout<<endl;
    fr(i,9){
        fr(j,9)cout<<a[i][j]<<' ';
    cout<<endl;
    }
    cout<<endl;
}

void try_it(int a[9][9]){
    fr(i,9)
        fr(j,9)
        if(a[i][j]==0){
            for(int k=1;k<=9;k++){
                if(  row_check(a,k,i) && col_check(a,k,j) && grid_check(a,k,i,j) ){
                    a[i][j] = k;   // print(a);
                    if(filled(a)){
                        print(a);
                        exit(0);
                    }
                    try_it(a);
                }
                //if(k==9)return;
            }
            a[i][j]=0;
            return;
        }
}

int main(){
    fr(i,9)
        fr(j,9)cin>>a[i][j];

        try_it(a);
}
