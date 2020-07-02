#include <bits/stdc++.h>
using namespace std;

vector<int>v1[30];
queue<int>mq;
string str[105];
int indegree[26];

int main()
{
	int n,x,y;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		cin>>str[i];
	}
	
	for(int i=0;i<n-1;i++)
	{
		int len=min(str[i].length(),str[i+1].length());
		
		x=-1;
		y=-1;
		for(int j=0;j<len;j++)
		{
			if(str[i][j]!=str[i+1][j])
			{
				x=str[i][j];
				y=str[i+1][j];
				break;
			}
		}
		if(x==-1)
		{
			if(str[i].length()>str[i+1].length())
			{
				cout<<"Impossible"<<endl;
				return 0;
			}
			continue;
		}
		x-='a';
		y-='a';
		v1[x].push_back(y);
		indegree[y]++;
	}
	
	for(int i=0;i<26;i++)
	{
		if(indegree[i]==0)
		{
			mq.push(i);
		}
	}
	string res="";
	
	while(!mq.empty())
	{
		int top=mq.front();
		mq.pop();
		res+=char(top+ 'a');
		int l=v1[top].size();
		
		for(int i=0;i<l;i++)
		{
			int k=v1[top][i];
			indegree[k]--;
			if(indegree[k]==0)
			{
				mq.push(k);
			}
		}
	}
		
	if(res.length()==26) cout<<res<<endl;
	else cout<<"Impossible"<<endl;
		
	return 0;
}
