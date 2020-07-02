#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long N,A,ans;
	
	while(scanf("%d%d",&N,&A)){
		
		ans = 0;
		for(int i=1;i<=N;i++)
		{
			ans+=i*pow(A,i);
		}
		
		printf("%ll\n",ans);
	}
	
	
	return 0;
}
