#include <bits/stdc++.h>
using namespace std;

map<string,int> mp;
vector<int> v1[250];
priority_queue<int, vector<int>, greater<int> >mq;

int indegree[250];


int main()
{
	int n,m;
	string s1,s2;
	char str[250][250];
	int c=1;
	while((cin>>n ) && EOF)
	{
		mp.clear();
		for(int i=0;i<=n;i++) v1[i].clear();

		for(int i=0;i<n;i++)
		{
			cin>>str[i];
			mp[str[i]]=i;
		}
		cin>>m;
		while(m--)
		{
			cin>>s1;
			int x=mp[s1];
			cin>>s2;
			int y=mp[s2];
			v1[x].push_back(y);
			indegree[y]++;
		}
		
		for(int i=0;i<n;i++)
		{
			if(indegree[i]==0) mq.push(i);
		}
		
		cout<<"Case #"<<c<<": Dilbert should drink beverages in this order:";
		c++;
		while(!mq.empty())
		{
			int top=mq.top();
			mq.pop();
			int len=v1[top].size();
			for(int i=0;i<len;i++)
			{
				int k=v1[top][i];
				indegree[k]--;
				if(indegree[k]==0) mq.push(k);
			}
			cout<<" "<<str[top];
		}
		cout<<"."<<endl;
		cout<<endl;
	}
	
	return 0;
}
