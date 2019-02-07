#include<bits/stdc++.h>
using namespace std;

int check(string a,string b)
{
	int l1=a.size();
	int l2=b.size();
	if(l1!=l2) return 0;
	int cnt=0;
	for(int i=0;i<l1;i++)
	{
		if(a[i]!=b[i]) cnt++;
	}
	if(cnt==1) return 1;
	else return 0;
}

int BFS(string str1,string str2,map<string,vector<string> >v1,map<string,int>visited)
{
	queue<string>mq;
	mq.push(str1);
	map<string,int>mp;
	mp[str1]=0;
	while(!mq.empty())
	{
		string top = mq.front();
		mq.pop();
		int len=v1[top].size();
		for(int i=0;i<len;i++)
		{
			string ks=v1[top][i];
			if(visited[ks]==0)
			{
				visited[ks]=1;
				mp[ks]=mp[top]+1;
				mq.push(ks);
				if(ks==str2) return mp[ks];
			}
		}
	}
	return -1;
}
	
	

int main()
{
	int t;
	cin>>t;
	cin.get();
	while(t--)
	{
		string str;
		map<string,vector<string> >v1;
		vector<string>v;
		map<string,int> visited;
		int k=0;
		
		while(1)
		{
			cin>>str;
			if(str=="*") break;
			v.push_back(str);
			visited[str]=0;
			k++;
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
		
		
		string str1,str2,s;
		getline(cin,s);
		while(1)
		{
			getline(cin,s);
			if(s== "") break;
			stringstream  ss(s);
			ss>>str1;
			ss>>str2;
			
			if(str1!=str2) cout<<str1<<" "<<str2<<" "<<BFS(str1,str2,v1,visited)<<endl;
			else cout<<str1<<" "<<str2<<" "<<"0"<<endl;
		}
		if(t) cout<<endl;
		
	}
	
	return 0;
}
