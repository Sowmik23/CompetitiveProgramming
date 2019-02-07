/*  Interesting problem solving with kruskal  */

#include <bits/stdc++.h>
using namespace std;

int parent[100005];
struct st{
	int a,b;
	double c,x,y;
}arr[100005],br[100005];

bool comp(st p,st q)
{
	return p.c<q.c;
}

void init(int n)
{
	for(int i=0;i<n;i++)
	{
		parent[i]=-1;
	}
}

int find(int d)
{
	if(parent[d]==-1) return d;
	return parent[d]=find(parent[d]);
}

double weight(double x1,double y1,double x2,double y2)
{
	double dd=x1-x2;
	double ee=y1-y2;
	double ff= sqrt(dd*dd+ee*ee);
	return ff;
}

int main()
{
	int test,n,ca=0;
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d",&n);
		init(n);
		for(int i=0;i<n;i++)
		{
			scanf("%lf%lf",&br[i].x,&br[i].y);
		}
		int k=0;
		
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				arr[k].a=i;
				arr[k].b=j;
				arr[k].c= weight(br[i].x,br[i].y,br[j].x,br[j].y);
				k++;
			}
		}
		sort(arr,arr+k,comp);
		double sum=0;
		for(int i=0;i<k;i++)
		{
			int jj=find(arr[i].a);
			int kk=find(arr[i].b);
			
			if(jj!=kk)
			{
				parent[jj]=kk;
				sum+=arr[i].c;
			}
		}
		if(ca) cout<<endl;
		printf("%.2lf\n",sum);
		ca++;
	}
	
	return 0;
}
