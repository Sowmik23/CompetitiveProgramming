#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		int d = (n*567)/9 + 7492;
		int k = (d*235)/47 - 498;
		//cout<<k<<endl;
		int x = k/10;
		int ans = x%10;
		cout<<abs(ans)<<endl;
	}
	
	return 0;
}
