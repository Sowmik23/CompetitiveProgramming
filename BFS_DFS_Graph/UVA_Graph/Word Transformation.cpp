#include <bits/stdc++.h>
using namespace std;

int check(string a,string b)
{
	int l1=a.size();
	int l2=b.size();
	int cnt=0;
	if(l1!=l2) return 0;
	else 
	{
		for(int i=0;i<l1;i++)
		{
			if(a[i]!=b[i]) cnt++;
		}
	}
	if(cnt==1) return 1;
	else return 0;
}

int BFS(string str1,string str2,map<string,vector<string> >v1,map<string,int>visited)
{
	map<string,int>mp;
	queue<string>mq;
	mq.push(str1);
	mp[str1]=0;
	while(!mq.empty())
	{
		string top=mq.front();
		mq.pop();
		int len=v1[top].size();
		for(int i=0;i<len;i++)
		{
			string k=v1[top][i];
			if(visited[k]==0)
			{
				visited[k]=1;
				mp[k]=mp[top]+1;
				mq.push(k);
				if(k==str2) return mp[k];
			}
		}
	}
	return -1;
}

int main()
{
	int t;
	scanf("%d",&t);
	cin.get();
	while(t--)
	{
		string str;
		map<string,vector<string> >v1;
        vector<string>v;
        map<string,int >visited;

		int k=0;
		while(1)
		{
			cin>>str;
			
			if(str=="*") break;
			v.push_back(str);
			k++;
			visited[str]=0;
			
		}
		for(int i=0;i<k;i++)
		{
			for(int j=0;j<k;j++)
			{
				if(check(v[i],v[j])==1)
				{
					v1[v[i]].push_back(v[j]);
					v1[v[j]].push_back(v[i]);
				}
			}
		}
		
		string s,str1,str2;
		getline(cin,s);
		while(1)
		{
			getline(cin,s);
			if(s=="") break;
			stringstream sss(s);
			sss>>str1;
			sss>>str2;
			
			if(str1!=str2) cout<<str1<<" "<<str2<<" "<<BFS(str1,str2,v1,visited)<<endl;
			else cout<<str1<<" "<<str2<<" "<<"0"<<endl;
		}
		if(t) cout<<endl;
	}
	return 0;
}
