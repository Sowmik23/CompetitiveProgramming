#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	int a = 1;
	int b = 1;
	int c,sum=2,cnt=2;
	if(n==1) cout<<"1"<<endl;
	else if(n==2) cout<<"2"<<endl;
	else 
	{
		while(1)
		{
			c = a+b;
			sum+=c;
			cnt++;
			if(cnt==n) break;
			a = b;
			b = c;
		}
		cout<<sum<<endl;
	}

	return 0;
}
