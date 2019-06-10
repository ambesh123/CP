#include<bits/stdc++.h>
#define pb push_back
#define fr(N)	for(long i=0;i<N;i++)
#define K 50

using namespace std;

int max_size;

struct tri{
	long sd[K];
};

int getMid(int s, int e) {  return s + (e -s)/2;  }

void merge(long b[],long c[],long a[]){	//merge b & c to a
	int o=0,t=0,f=0;
	for(f=0;f<K;f++){
		if(b[o]>c[t]){
			a[f]=b[o]; o++;
		}
		else{
			a[f]=c[t]; t++;
		}
	}
}

long getPerimeter(tri s){
	for(int i=0;i<K-2;i++){
		if(s.sd[i] < (s.sd[i+1]+ s.sd[i+2])){
			return s.sd[i]+s.sd[i+1]+s.sd[i+2];
		}
	}
	return 0;
}

tri getMaxUtil(tri *st, int ss, int se, int qs, int qe, int si)
{

    if (qs <= ss && qe >= se)
        return st[si];

    if (se < qs || ss > qe)
        return *(new tri());

    int mid = getMid(ss, se);
    tri one = getMaxUtil(st, ss, mid, qs, qe, 2*si+1);
    tri two = getMaxUtil(st, mid+1, se, qs, qe, 2*si+2);
    tri temp = *(new tri());
    merge(one.sd,two.sd,temp.sd);
    return temp;
}

void updateValueUtil(tri *st, int ss, int se, int i,long newVal, int si)
{
    if (i < ss || i > se)
        return;
    if(se==ss)st[si].sd[0]=newVal;
    else
    {
        int mid = getMid(ss, se);
        updateValueUtil(st, ss, mid, i,newVal, 2*si + 1);
        updateValueUtil(st, mid+1, se, i,newVal, 2*si + 2);
        merge(st[2*si+1].sd,st[2*si+2].sd,st[si].sd);
    }
}

void updateValue(long arr[], tri *st, int n, int i, long new_val)
{
    updateValueUtil(st, 0, n-1, i,new_val, 0);
    arr[i] = new_val;
}
tri getMaxSides(tri *st, int n, int qs, int qe)
{

    return getMaxUtil(st, 0, n-1, qs, qe, 0);
}

tri constructSTUtil(long arr[], int ss, int se, tri *st, int si)
{
    if (ss == se)
    {
		tri *Tri = new tri();
		Tri->sd[0]=arr[ss];
		st[si]=*Tri;
		//int m=0; cout<<si<<". "; while(st[si].sd[m]!=0){cout<<st[si].sd[m]<<' '; m++;}cout<<endl;
		return st[si];
    }
    int mid = getMid(ss, se);
    tri one=  constructSTUtil(arr, ss, mid, st, si*2+1);
    tri two= constructSTUtil(arr, mid+1, se, st, si*2+2);
	merge(one.sd,two.sd,st[si].sd);
	//int m=0; cout<<si<<". "; while(st[si].sd[m]!=0){cout<<st[si].sd[m]<<' '; m++;}cout<<endl;
	return st[si];
}
tri *constructST(long arr[], int n)
{
    int x = (int)(ceil(log2(n)));
    max_size = 2*(int)pow(2, x) - 1;
    tri *st = new tri[max_size];
    constructSTUtil(arr, 0, n-1, st, 0);
    //cout<<"Tree contains:\n";	int m,p; for(p=0;p<max_size;p++){m=0; cout<<p<<". "; while(st[p].sd[m]!=0 &&m<K){cout<<st[p].sd[m]<<' '; m++;}cout<<endl;}
    return st;
}

int main()
{
	int n,Q,q,l,r,pos;
	long val;
	cin>>n>>Q;
    long arr[n];
    fr(n)cin>>arr[i];
    tri *st = constructST(arr, n);
    while(Q--){
    	cin>>q;
    	if(q==1){
    		cin>>pos>>val;
			updateValue(arr,st,n,pos-1,val);
    	}
		else{
			cin>>l>>r;
			cout<<getPerimeter(getMaxSides(st,n,l-1,r-1))<<'\n';
		}
	}
}
