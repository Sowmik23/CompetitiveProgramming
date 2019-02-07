#include <stdio.h>

long long mod = 1e9;

long long arr[100],visited[1000010][22];

long long int dp(long long n,long long k)
{
	if(n==0) return 1;
	if(n<0) return 0;
	
	if(visited[n][k]!=-1) return visited[n][k];
	long long res = 0;
	
	for(int j=k;j>=0;j--)
	{
		res = (res + (dp(n-arr[j],j)));
		res%=mod;
	}
	return visited[n][k]=res;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	long long n,x;
	scanf("%lld",&n);
	arr[0]=1;
	int k=1,m;
	long long nn=n;
	while(nn>0)
	{
		x = arr[k-1]*2;
		arr[k]=x;
		nn-=x;
		k++;
	}
	m=k;
	
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=m;j++) visited[i][j] = -1;
	}
	printf("%lld\n",dp(n,m-1));
	
	return 0;
}
