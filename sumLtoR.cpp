// Program to add a new no. in an array from l to r in O(1) complexity
#include<iostream>
#define fr(n)	for(int i=0;i<n;i++)
using namespace std;

void show(int a[],int b[],int n){
	long sum;
	fr(n){
		sum=0;
		for(int j=0;j<=i;j++)sum+=a[j];
		cout<<b[i]+sum<<"\t";
	}
	cout<<'\n';
}

main(){
	int n,q,l,r,ele;
	cin>>n;
	int a[n]={0},b[n];	//create an array of size n and initialize every element with 0.
	fr(n)cin>>b[i]; // take input of array
	cin>>q;   // no. of queries to be executed;
	while(q--){
		cin>>l>>r; //left and right limits
		cin>>ele;	//element to add in [l,r]
		a[l]+=ele;
		if(r<n-1)a[r+1]-=ele;
		//cout<<"Array became: "; show(a,b,n);   //uncomment to see update at each stage
	}
	show(a,b,n); //final result
	return 0;
}
