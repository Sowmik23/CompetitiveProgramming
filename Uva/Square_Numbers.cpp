#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a,b,res1,res2,ans;
	while(scanf("%d%d",&a,&b)==2)
	{
		if(a==0 and b==0) break;
		
		res1 = ceil(sqrt(a));
		res2 = floor(sqrt(b));
		
		//cout<<res1<<" "<<res2<<endl;
		
		ans = res2 - res1;
		//if(res1*res1==a) ans++;
		//if(res2*res2==b) ans++;
		
		printf("%d\n",ans+1);
	}

	return 0;
}
