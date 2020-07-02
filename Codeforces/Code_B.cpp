#include <bits/stdc++.h>
using namespace std;

const int N = 2e3;
int a[N],ans[N];
pair<int,int>p[N];

int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		p[i]={ a[i] , i+1 };
	}
	sort(p,p+n);
	
	int sum=0;
	for(int i=n-1,j=0;i>=0 && j<k;i--,j++)
	{
		sum+=p[i].first;
		ans[j]=p[i].second;
	}
	sort(ans,ans+k);
	ans[k-1]=n;
	cout<<sum<<endl;
	
	cout<<ans[0];
	for(int i=1;i<k;i++)
	{
		cout<<" "<<ans[i]-ans[i-1];
	}
	puts("");
	
	
	return 0;
}
