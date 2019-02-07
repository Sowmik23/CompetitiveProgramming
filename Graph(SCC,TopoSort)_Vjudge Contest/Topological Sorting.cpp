#include <bits/stdc++.h>
using namespace std;

/*So topological sorting can be 
 * achieved for only directed and acyclic graphs.
 * means that the graph which has no cycle.  */

struct compare{
	
	bool operator ()(const int x,const int y)
	{
		return x>y;
	}
};

priority_queue<int,vector<int>,compare> mq;
vector<int>v1[1000009];	
vector<int>ans;
int indegree[1000009],flag=0;

void dfs_visit()
{
	while(!mq.empty())
	{
		int top=mq.top();
		mq.pop();
		ans.push_back(top);
		int len=v1[top].size();
		for(int i=0;i<len;i++)
		{
			int k=v1[top][i];
			indegree[k]--;
			if(indegree[k]==0) mq.push(k);
		}
	}
}

void topo_sort(int n)
{
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(indegree[i]==0) 
		{
			mq.push(i);
		}
		else cnt++;
	}
	if(cnt==n)
	{
		flag=1;
		return ;
	}
	dfs_visit();
}

int main()
{
	int n,m,x,y;
	scanf("%d%d",&n,&m);
	while(m--)
	{
		scanf("%d%d",&x,&y);
		v1[x].push_back(y);
		indegree[y]++;
	}
	
	topo_sort(n);
	
	
	int l=ans.size();
	//cout<<flag<<" "<<" "<<l<<endl;

	if(flag || l!=n) 
	{
		cout<<"Sandro fails."<<endl;
	}
	else 
	{
		for(int i=0;i<l;i++)
		{
			if(i) cout<<" ";
			cout<<ans[i];
		}
		cout<<endl;
	}

	return 0;
}
