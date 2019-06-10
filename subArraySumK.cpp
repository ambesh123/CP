					   //  @ /\/\ BESH //

#include<bits/stdc++.h>
using namespace std;

#define inp_out_wrk ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define fr(n) for(long long i=0;i<n;i++)

long long subArraySum(long long arr[], long long n, long long sum)
{
    unordered_map<long long, long long> map;
 	long long count=0;
    long long curr_sum = 0;
 
    for (long long i = 0; i < n; i++)
    {
        curr_sum = curr_sum + arr[i];
 
        if (curr_sum == sum)
        {
            count++;
        }
        if (map.find(curr_sum - sum) != map.end())
        {
           count = map[curr_sum - sum] + count;
        }
 
        map[curr_sum] ++;
    }
    return count;
}


int main()
{	
	long long n;
	cin>>n;
	long long a[n],arr[n];
	fr(n)cin>>a[i];
	fr(n){
			if(a[i] & 1)arr[i]=-1;
			else arr[i]=1;
	}
	cout<<subArraySum(arr,n,0);
	return 0;
}
