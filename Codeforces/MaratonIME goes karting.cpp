#include <bits/stdc++.h>
using namespace std;

struct st{
	long long int score,indx;
}arr[500000];

bool comp(st x,st y)
{
	return x.score>y.score;
}

int main()
{
	long long int n;
	scanf("%lld",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%lld",&arr[i].score);
		arr[i].indx=i+1;
	}
	sort(arr,arr+n,comp);
	if(n==1 ) cout<<"1\n";
	else if(arr[0].score==arr[1].score) cout<<"-1\n";
	else cout<<arr[0].indx<<endl;
	
		
	return 0;
}

