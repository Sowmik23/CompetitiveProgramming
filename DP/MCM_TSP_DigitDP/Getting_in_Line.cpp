#include <bits/stdc++.h>
using namespace std;

int n,arr[10],brr[10],sequence[10],min_sequence[10],visited[10];
double mn,dis[10][10];

double distance(int x1,int y1,int x2,int y2)
{
	double d1 = x1-x2;
	double d2 = y1-y2;
	double res = sqrt(d1*d1 + d2*d2);
	return res;
}

void dp(int pre,int cnt,double length)
{
	if(cnt==n)
	{
		if(mn>length)
		{
			mn = length;
			for(int i=0;i<n;i++)
			{
				min_sequence[i] = sequence[i];
			}
		}
		return ;
	}
	for(int i=0;i<n;i++)
	{
		if(visited[i]==0)
		{
			visited[i] =1;
			sequence[cnt] = i;
			
			dp(i,cnt+1,length+dis[pre][i]);
			
			visited[i] = 0;
		}
	}
}

int main()
{
	int t=1;
	while(scanf("%d",&n))
	{
		if(n==0) break;
		for(int i=0;i<n;i++) scanf("%d%d",&arr[i],&brr[i]);
		
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				dis[i][j] = dis[j][i] = distance(arr[i],brr[i],arr[j],brr[j]);
				//cout<<dis[i][j]<<endl;
			}
		}
		
		mn = 1e9;
		
		for(int i=0;i<n;i++)
		{
			sequence[0]=i;
			visited[i]= 1;
			dp(i,1,0);
			visited[i]=0;
		}		
		
		printf("**********************************************************\n");
		printf("Network #%d\n",t++);
		for(int i=0;i<n-1;i++)
		{
			printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2lf feet.\n",arr[min_sequence[i]],brr[min_sequence[i]], arr[min_sequence[i+1]],brr[min_sequence[i+1]],  dis[min_sequence[i]][min_sequence[i+1]]+16);
		}
		printf("Number of feet of cable required is %.2lf.\n",(mn+16.0*(n-1)));
	}
	
	return 0;
}
