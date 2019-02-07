#include <bits/stdc++.h>
using namespace std;

int n,arr[105][105],ans[1000];

int find_max()
{
	int cur_sum = ans[0],sum =0;
	for(int l=0;l<n;l++)
	{
		//cout<<ans[l]<<" ";
		sum+=ans[l];
		cur_sum = max(sum,cur_sum);
		if(sum<0) sum = 0;
	}
	//cout<<endl;
	//cout<<"Current sum for this array: "<<cur_sum<<endl;
	return cur_sum;
}

int fun()
{
	int mx = -2000;
	for(int i=0;i<n;i++)
	{
		memset(ans,0,sizeof(ans));
		
		for(int j=i;j<n;j++)
		{
			for(int k=0;k<n;k++)
			{
				ans[k]+= arr[j][k];
				//cout<<ans[k]<<" ";
				mx = max(mx,find_max());
				//cout<<"mx: "<<mx<<endl;
			}
			//cout<<endl;
		}
	}
	return mx;
}

int main()
{
	scanf("%d",&n);
	for(int  i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}
	printf("%d\n",fun());
	
	return 0;
}

/*
input: 

4
0  -2  -7    0
9    2  -6    2
-4    1  -4    1  
-1     8    0  -2
*/
