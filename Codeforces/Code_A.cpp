#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,k,a[100];
	string str;
	scanf("%d%d",&n,&k);
	cin>>str;
	int len=str.size();
	for(int i=0;i<len;i++)
	{
		a[i]=str[i]-'a'+1;
	}

	sort(a,a+len);
	
	int cnt=0,sum=0;
	for(int i=0;i<len;i++)
	{
		
		if(a[i]==a[i+1]+1 || a[i]+1==a[i+1])
		{
			cnt++;
			sum+=a[i];		
			
			if(cnt==k)
			{ 
				cout<<sum<<endl; 
				return 0;
			}

			i++;
		}
		
		else if(a[i]+1<a[i+1]) 
		{
			cnt++;
			sum+=a[i];
			
			if(cnt==k)
			{ 
				cout<<sum<<endl; 
				return 0;
			}

		}
	}
	cout<<"-1"<<endl;
	
	return 0;
}
