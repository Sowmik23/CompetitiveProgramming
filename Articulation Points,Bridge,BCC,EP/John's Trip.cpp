#include <bits/stdc++.h>
using namespace std;             
								
									
vector<pair<int,int> >v1[100005];
vector<int>stk2;
stack<int>stk;
pair<int,int>pa;
map<pair<int,int>,int >mp;
set<int>sst[100005];

int degree[100005],start;

struct st{
	int u,v,w;
}arr[100005];

bool comp(st x,st y)
{
	return x.w<y.w;
}

int isEuler(int n)
{
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		if(v1[i].size()%2!=0) 
		{
			cnt=1;
			break;
		}
	}
	if(cnt==0) return 1;
	else return 0;
}

void dfs(int x)
{
	for(int i=0;i<v1[x].size();i++)
	{
		int t=v1[x].back().first;
		v1[x].pop_back();
		vector<pair<int,int> >:: iterator it;
		for(it=v1[t].begin();it!=v1[t].end();it++)
		{
			if(it->first==x)
			{
				v1[t].erase(it);break;
			}	
		}
		dfs(t);
	}
	stk.push(x);
}

int main()
{
	int n,m,name;
	while(1)
	{
		int mx=0;
		scanf("%d%d",&n,&m);
		int i=0;
		if(n==0 and m==0) break;
		else 
		{
			start=min(n,m);
			mx= max(mx,max(n,m));
			scanf("%d",&name);
			arr[i].u= n;
			arr[i].v= m;
			arr[i].w = name;
			i++;
			degree[n]++;
			degree[m]++;
			while(scanf("%d%d",&n,&m))
			{
				if(n==0 and m==0) break;
				scanf("%d",&name);
				mx= max(mx,max(n,m));
				arr[i].u= n;
				arr[i].v= m;
				arr[i].w = name;
				i++;
				degree[n]++;
				degree[m]++;
			}
			
			
				sort(arr,arr+i,comp);
				int cnt=1;
				for(int j=0;j<i;j++)
				{
					v1[arr[j].v].push_back({arr[j].u,arr[j].w});
					v1[arr[j].u].push_back({arr[j].v,arr[j].w});
					
					if(arr[j].u < arr[j].v) 
					{
						pa = make_pair(arr[j].u,arr[j].v );
				
						if(mp[pa]==0)
						{
							 mp[pa] = cnt;
							 sst[cnt].insert(arr[j].w);
							 cnt++;
						}
						else 
						{
							sst[mp[pa]].insert(arr[j].w);
						}

					}
					else 
					{
						pa = make_pair(arr[j].v,arr[j].u );
				
						if(mp[pa]==0)
						{
							 mp[pa] = cnt;
							 sst[cnt].insert(arr[j].w);
							 cnt++;
						}
						else 
						{
							sst[mp[pa]].insert(arr[j].w);
						}
					}
				}

				if(isEuler(mx)==0)
				{
					printf("Round trip does not exist.\n\n");
				}
				else 
				{
					dfs(start);
					while(!stk.empty())
					{
						stk2.push_back(stk.top());
						stk.pop();
					}
					
					for(int ll=stk2.size()-1;ll>0;ll--)
					{
						int x=stk2[ll];
						int y=stk2[ll-1];
						pa={min(x,y),max(x,y)};
						if(mp[pa]!=0) 
						{
							int value=mp[pa];
							if(ll!=stk2.size()-1) cout<<" ";
							cout<<*sst[value].begin();
							sst[value].erase(sst[value].begin());
						}
					}
					cout<<endl<<endl;
				}
			
		}
		for(int i=0;i<=n;i++)
		{
			v1[i].clear();
			sst[i].clear();
		}
		mp.clear();
		stk2.clear();
	}
	return 0;
}
