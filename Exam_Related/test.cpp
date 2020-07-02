#include <bits/stdc++.h>
using namespace std;

int main()
{
	int cnt=0;
	for(int i=19*6;i<=999;i++)
	{
		if(i%19==0)cnt++;
	}
	cout<<cnt<<endl;

	return 0;
}
