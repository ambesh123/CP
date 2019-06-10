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

string memo[1000][1000];

void ini(){
    fr(i,1000)fr(j,1000)memo[i][j] = "null";
}

string lcs(string &s1, string &s2,int i1,int i2){
    if(i1 <0 || i2<0)return "";
    if(memo[i1][i2]!="null")return memo[i1][i2];
    if(s1[i1] == s2[i2]){
        return memo[i1][i2] = lcs(s1,s2,i1-1,i2-1) + s1[i1];
    }
    else{
        string l1 = lcs(s1,s2,i1-1,i2) , l2 = lcs(s1,s2,i1,i2-1);
        if(l1.length()>l2.length())return memo[i1][i2] = l1;
        else return memo[i1][i2] = l2;
    }
}

string lcsTabular(string s1,string s2){
    string table[s1.length()][s2.length()];
    fr(i,s1.length())if(s1[i] == s2[0])table[i][0] = "" + s2[0]; else table[i][0] = "";
    fr(i,s2.length())if(s1[0] == s2[i])table[0][i] = "" + s1[0]; else table[0][i] = "";
    for(int i = 1; i< s1.length(); i++){
        for(int j = 1; j<s2.length();j++){
            if(s1[i] == s2[j])
                table[i][j] = table[i-1][j-1] + s2[j];
            else
                table[i][j] = (table[i-1][j].length()>table[i][j-1].length())? table[i-1][j] : table[i][j-1];
        }
    }
    return table[s1.length()-1][s2.length()-1];
}


int main(){
    ini();
    string s1 = "Mzxnxzmnai Hpoirpooon Dono Ka Do,.n Ulklsdjftimataskldjflely I am known as supoiewuroier dooper don!!";
    string s2 = "qwwq.Mai H,mznv,mnoon Dlsakjdflono Kaslkdjflkaa Don Ultimately I am knalvlaksnvnown as super dooper don!!!";
    int n = s1.length()-1;
    int m = s2.length()-1;
    cout<<lcs(s1,s2,n,m)<<endl;
    //cout<< lcsTabular(s1,s2);
}
