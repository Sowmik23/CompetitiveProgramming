#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	long long int a[n];
	int p=0;
	for(int i=0;i<n;i++)
	{	
		cin>>a[i];
	}
	if(n==1) cout<<"0"<<endl;
	else {
		
		long long int sum1=a[0],sum3=a[n-1];
		long long int ans;
		int i=1;
		int j=n-2;
		p=0;
		while(1)
		{
			if(i>=j) break;
			
			if(sum1==sum3)
			{
				p=1;
				ans=sum1;
			}
			if(sum1<sum3)
			{
				sum1+=a[i];
				i++;
			}
			if(sum3<sum1) 
			{
				sum3+=a[j];
				j--;
			}
			
		}
		if(p==1) cout<<ans<<endl;
		else cout<<"0"<<endl;
	}
	
	return 0;
}
