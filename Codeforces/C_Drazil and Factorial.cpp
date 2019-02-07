#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long int n,x;

	int arr2[] = {2};
	int arr3[] = {3};
	int arr4[] = {3,2,2};
	int arr5[] = {5};
	int arr6[] = {5,3};
	int arr7[] = {7};
	int arr8[] = {7,2,2,2};
	int arr9[] = {7,3,3,2};
	
	long long int brr[2000];
	
	scanf("%lld",&n);
	scanf("%lld",&x);
	
	long long k,i=0 ;
	
	while(x>0)
	{
		k=x%10;
		if(k!=0 or k!=1) 
		{
			if(k==2) brr[i++]=arr2[0];
			else if(k==3) brr[i++] = arr3[0];
			else if(k==4) for(int j=0;j<3;j++) brr[i++]=arr4[j];
			else if(k==5) brr[i++] = arr5[0];
			else if(k==6) for(int j=0;j<2;j++) brr[i++]=arr6[j];
			else if(k==7) brr[i++] = arr7[0];
			else if(k==8) for(int j=0;j<4;j++) brr[i++]=arr8[j];
			else if(k==9) for(int j=0;j<4;j++) brr[i++]=arr9[j];
		}
		x/=10;
	}
	sort(brr,brr+i,greater<int>());
	for(int j=0;j<i;j++) cout<<brr[j];
	cout<<endl;

	
	return 0;
}
