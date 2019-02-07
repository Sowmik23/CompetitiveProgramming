#include <bits/stdc++.h>
using namespace std;

int main()
{
	int arr[5];
	for(int i=1;i<=4;i++)
	{
		scanf("%d",&arr[i]);
	}
	int ans=0;
	string str;
	cin>>str;
	for(int i=0;i<str.size();i++)
	{
		int x = str[i]-'0';
		ans+=arr[x];
		//cout<<x<<" "<<arr[x]<<endl;
	}
	printf("%d\n",ans);
	
	
	return 0;
}
