#include <bits/stdc++.h>
using namespace std;
map<string,vector<string> >route ;
map<string,int>visited;

int bfs(string start,string endd,map<string,vector<string> > v1)
{
	queue<string>mq;
	mq.push(start);
	visited[start]=1;
	while(!mq.empty())
	{
		string top = mq.front();
		mq.pop();
		if(top==endd) return visited[top];
		int len=v1[top].size();
		for(int i=0;i<len;i++)
		{
			string n=v1[top][i];
			if(visited[n]==-1)
			{
				visited[n]=visited[top]+1;
				route[n]=top;
				mq.push(n);
			}
		}
	}
	return -1;
}

void printpath(string endd,string start)
{
	if(endd==start) return;
	printpath(route[endd],start);
	cout<<route[endd]<<" "<<endd<<endl;
}

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		map<string,vector<string> >v1;
		string s1,s2,start,endd;
		for(int i=0;i<n;i++)
		{
			cin>>s1>>s2;
			v1[s1].push_back(s2);
			v1[s2].push_back(s1);
			visited[s1]=-1;
			visited[s2]=-1;
		}
		cin>>start>>endd;
		if(bfs(start,endd,v1)!=-1) printpath(endd,start);
		else printf("No route\n");
	}
	
	return 0;
}
