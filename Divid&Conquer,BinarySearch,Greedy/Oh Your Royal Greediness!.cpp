#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int> > v1;
vector<pair<int,int> >::iterator it;
pair<int,int>pa;

int main()
{
	int test=1,n,a,b;
	while(scanf("%d",&n))
	{
		if(n==-1) break;
		v1.clear();
		for(int i=0;i<n;i++)
		{
			scanf("%d%d",&a,&b);
			pa = make_pair(a,-1);
			v1.push_back(pa);
			pa = make_pair(b,1);
			v1.push_back(pa);
		}
		sort(v1.begin(),v1.end());
		int mx=0,cnt=0;
		for(it=v1.begin();it!=v1.end();it++)
		{
			//cout<<it->first<<" "<<it->second<<endl;
			mx = max(mx,cnt-=it->second);
		}
		
		printf("Case %d: %d\n",test++,mx);
	}
	
	return 0;
}
