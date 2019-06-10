#include <bits/stdc++.h>
#define inp_out_work ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define testCase    int T; cin>>T; while(T--)
#define fr(i,n) for(int i=0;i<n;i++)
#define rfr(i,n) for(int i=n-1;i>=0;i--)
#define fro(i,s,e) for(int i=s;i<=e;i++)
#define pb push_back
#define debug(P) cout<<#P<<' '<<P<<endl
#define endl '\n'
#define FILE freopen("in.txt","r",stdin); freopen("out.txt","w",stdout);

using namespace std;

typedef long long ll;
const int mod = 1000000007;
const int MAXN = 501;

template<class T>
T gcd(T a , T b , T &x , T &y){
    if(b == 0){
        x = 1  , y = 0;
        return a;
    }
    int g = gcd(b , a%b , x , y);
    T tx= y;
    T ty = x - floor(a/b)*y;
    x = tx , y = ty;
    return g;
}

int main(){
    cout<<"In equation ax + by = c \n enter values of a , b , c respectively : ";
    int a , b , c;
    cin>>a>>b>>c;
    if(c < 0)exit(0);
    int x , y;
    int g = gcd(a , b , x , y);
    if(c%g != 0){
        cout<<"No solution exist for given equation";
        return 0;
    }
    else{
        int m = c / g;
        x *=  m , y *= m;
        cout<< "Possible solution is : " << x << ' ' << y << endl;
        int lcm = (a*b)/g;
        int ix = lcm / a , iy = lcm/b;

        while(x < 0){
            x += ix , y -= iy;
        }
        while(y < 0){
            y += iy , x -= ix;
        }
        if(x < 0) cout<< "No positive solutions possible ";
        else
        cout<<"Positive solutions are : " << x <<' ' << y << endl;
    }
}
