#include <bits/stdc++.h>
#define inp_out_work ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define testCase    int T; cin>>T; while(T--)
#define fr(i,n) for(int i=0;i<n;i++)
#define rfr(i,n) for(int i=n-1;i>=0;i--)
#define fro(s,e) for(int i=s;i<=e;i++)
#define pb push_back
#define ll long long
#define MAXN 10000
#define mod 1000000007

using namespace std;

int main()
{
    int n;
    cin>>n;
    string dna;
    cin>>dna;
    int psa[n]={0},psc[n]={0},pst[n]={0},psg[n]={0};
    int rc=n/4;
    bool oka,okc,okt,okg;

    fr(i,n)switch(dna.at(i)){
    case 'A': psa[i]++;
        break;
    case 'C': psc[i]++;
        break;
    case 'T': pst[i]++;
        break;
    case 'G': psg[i]++;
        break;
    }
    fro(1,n-1){ psa[i]+=psa[i-1]; psc[i]+=psc[i-1]; pst[i]+=pst[i-1]; psg[i]+=psg[i-1]; }
    //fr(i,n)cout<<psa[i]<<' '<<psc[i]<<' '<<pst[i]<<' '<<psg[i]<<'\n';

    if(rc-psa[n-1] >= 0)oka=true;
    else oka=false;
    if(rc-psc[n-1] >= 0)okc=true;
    else okc=false;
    if(rc-pst[n-1] >= 0)okt=true;
    else okt=false;
    if(rc-psg[n-1] >= 0)okg=true;
    else okg=false;

    unordered_map<int,int> mpa,mpc,mpt,mpg;
    int minSubLength=INT_MAX;
    int temp;
    fr(i,n){
        temp = 0;
        mpa[psa[i]]=i+1;
        mpc[psc[i]]=i+1;
        mpt[pst[i]]=i+1;
        mpg[psg[i]]=i+1;
        if( (oka || mpa[ psa[i] -(psa[n-1] - rc)]!=0) && (okc || mpc[ psc[i] -(psc[n-1] - rc)]!=0) && (okt || mpt[ pst[i] -(pst[n-1] - rc)]!=0) && (okg || mpg[ psg[i] -(psg[n-1] - rc)]!=0)  ){
            //cout<<"satisfied for i= "<<i<<endl;
            if(!oka)temp = i+1 - mpa[ psa[i] -(psa[n-1] - rc)];
            if(!okc)if(temp < i+1 - mpc[ psc[i] -(psc[n-1] - rc)])temp = i+1 - mpc[ psc[i] -(psc[n-1] - rc)];
            if(!okt)if(temp < i+1 - mpt[ pst[i] -(pst[n-1] - rc)])temp = i+1 - mpt[ pst[i] -(pst[n-1] - rc)];
            if(!okg)if(temp < i+1 - mpg[ psg[i] -(psg[n-1] - rc)])temp = i+1 - mpg[ psg[i] -(psg[n-1] - rc)];
            if(temp<minSubLength)minSubLength = temp;
        }
    }
    cout<<minSubLength;
}
