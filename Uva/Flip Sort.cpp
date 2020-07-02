#include <bits/stdc++.h>
using namespace std;

int n,arr[1009],cnt;

void merge(int l,int m,int r)
{ 
	int i,j,k,n1,n2;
	n1 = m-l+1;
	n2 = r-m;
	int b[n1],c[n2];
	for(i=0;i<n1;i++)
	{
		b[i] = arr[l+i];
	}
	for(j=0;j<n2;j++)
	{
		c[j] = arr[m+1+j];
	}
	i=0,j=0,k=l;
	while(i<n1 and j<n2)
	{
		if(b[i]<=c[j])
		{
			arr[k]=b[i];
			i++;
		}
		else 
		{
			cnt+=n1 - i;
			
			arr[k] = c[j];
			j++;
		}
		k++;
	}
	while(i<n1)
	{
		arr[k] = b[i];
		i++;
		k++;
	}
	while(j<n2)
	{
		arr[k] = c[j];
		k++;
		j++;
	}
}

void mergeSort(int l,int r)
{
	int m;
	if(l<r)
	{
		m = l+(r-l)/2;
		mergeSort(l,m);
		mergeSort(m+1,r);
		merge(l,m,r);
	}
}

int main()
{
	while(scanf("%d",&n) !=EOF)
	{
		for(int i=0;i<n;i++)
		{
			scanf("%d",&arr[i]);
		}
		cnt = 0;
		mergeSort(0,n-1);
		printf("Minimum exchange operations : %d\n",cnt);	
	}
	
	return 0;
}
