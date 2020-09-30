#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,cnt;
	cnt=0;
	n=100;
	for(int j=2;j<=100;j++)
	{
		bool p=false;
		for(int i=2;i*i<=n;i++)
		{
			if(j%i==0){p=false; break; }
			else p=true;
		}
		if(p==true)
		{
			cnt++;
			cout<<j<<" "<<endl;
		}
	}
	cout<<"Total prime Number from 1 to "<<n<<": "<<cnt<<endl;
	
	return 0;
}
