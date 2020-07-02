#include <bits/stdc++.h>
using namespace std;

#define mx 1000000    // eita tle khay na good code complexity;

int main()
{	
	vector<int> v1= vector<int>(mx+1,1);
	vector<int>ans;
	ans.push_back(0);
	ans.push_back(1);
	
	//by this i determine the number of divisors of 2 to mx in v1[n];
	for(int i=2;i<=mx;i++)
	{
		for(int j=i;j<=mx;j+=i)
		{
			v1[j]+=1;
		}
	}
	//for(int i=2;i<=100;i++) cout<<i<<" "<<v1[i]<<endl;

	int c,i=2;
	while(1)     
	{
		c = ans[i-1] + v1[ans[i-1]];
		if(c>mx) break;
		ans.push_back(c);
		i++;
	}

	int n,x,y,a,b;
	
	scanf("%d",&n);
	for(int k=1;k<=n;k++)
	{
		scanf("%d%d",&x,&y);
		a = lower_bound(ans.begin(), ans.end(), x) - ans.begin();
		b = upper_bound(ans.begin(), ans.end(), y) - ans.begin();
		printf("Case %d: %d\n",k,b-a);
	}
	
	return 0;
}


