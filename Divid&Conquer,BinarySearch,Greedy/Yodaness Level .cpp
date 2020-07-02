#include <bits/stdc++.h>
using namespace std;
								/* This is an important emample
								 * of binary indexed tree (BIT)
								 * Also another solving approach is 
								 * merge sort/counting inversions*/
vector<pair<int,int> >v1;
map<string,int>mp;
int bit[1000000],mx;

int query(int idx)
{
	long long res=0;
	while(idx)
	{
		res += bit[idx];
		idx-= (idx & -idx);
	}
	return res;
}

void update(long long idx,long long val)
{
	while(idx<=mx)
	{
		bit[idx]+=val;
		idx += (idx & -idx);
	}
}

int main()
{
	int test,n;
	string word;
	
	scanf("%d",&test);
	while(test--)
	{
		v1.clear();
		mp.clear();
		memset(bit,0,sizeof(bit));
		
		scanf("%d",&n);
		mx = n+10;
		for(int i=1;i<=n;i++) 
		{
			cin>>word;
			mp[word]=i;
		}
		for(int i=1;i<=n;i++)
		{
			cin>>word;
			int k=mp[word];
			v1.push_back(make_pair(k,i));
		}
		sort(v1.begin(),v1.end());
		reverse(v1.begin(),v1.end());
		
		int ans=0;
		for(int i=0;i<v1.size();i++)
		{
			int val = v1[i].first;
			int idx = v1[i].second;
			//cout<<val<<" "<<idx<<endl;
			ans+=query(idx);
			update(idx,1);
		}
	
		printf("%d\n",ans);
	}
	
	return 0;
}
