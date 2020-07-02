/*  kruskal algorithm for mst using union_find  */

#include <bits/stdc++.h>
using namespace std;

vector<pair<pair<int,int> ,int> >v1; //node,node,cost
int parent[100005];

struct st{
	int a,b,c;
};

bool comp(st x,st y)
{
	return x.c<y.c;
}

void init(int n)
{
	for(int i=0;i<n;i++)
	{
		parent[i]=-1;
	}
}

int find(int parent[],int x)
{
	if(parent[x]==-1) return x;
	return parent[x]=find(parent,parent[x]);
}
	
int main()
{
	st arr[10005];
	int n,m;
	scanf("%d%d",&n,&m); //node,edges
	init(n);
	for(int i=0;i<m;i++)
	{
		scanf("%d%d%d",&arr[i].a,&arr[i].b,&arr[i].c);  //node,node,cost
	}
	sort(arr,arr+m,comp);  //sort the edges according to their cost in choto theke boro
	
	int sum=0;
	for(int i=0;i<m;i++)
	{
		int xx=find(parent,arr[i].a);
		int yy=find(parent,arr[i].b);
		
		if(xx!=yy)
		{
			parent[xx]=yy;
			sum+=arr[i].c;
			v1.push_back( { {arr[i].a,arr[i].b } , arr[i].c } );
		}
	}
	cout<<"Weight of MST: "<<sum<<endl;
	cout<<"MST edges are: "<<endl;
	//sort(v1.begin(),v1.end());
	int len=v1.size();
	for(int i=0;i<len;i++)
	{
		cout<<v1[i].first.first<<" "<<v1[i].first.second<<endl;//<<" "<<v1[i].second<<endl;
	}
	
	return 0;
}
/*
input
9 14
0 1 4
0 7 8
1 2 8
1 7 11
2 3 7
2 8 2
2 5 4
3 4 9
3 5 14
4 5 10
5 6 2
6 7 1
6 8 6
7 8 7 
output = 37
*/
