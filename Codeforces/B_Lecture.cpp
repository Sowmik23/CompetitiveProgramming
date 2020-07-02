#include <bits/stdc++.h>
using namespace std;

map<int,pair<string,string> >mp;
map<string,int> mp1,mp2;


int main()
{
	int n,m;
	string str1,str2,str;
	
	scanf("%d%d",&n,&m);
	
	for(int i=0;i<m;i++){
		cin>>str1>>str2;
		mp1[str1]=i;
		mp2[str2] =i;
		mp[i] = make_pair(str1,str2);
	}
	
	//for(int i=0;i<m;i++){
		//cout<<mp[i].first.size()<<" "<<mp[i].second<<endl;
	//}
	
	for(int i=0;i<n;i++)
	{
		cin>>str;
		if(i) printf(" ");
		
		if(mp.count(mp1[str])!=0)
		{
			//cout<<"1 ";
			int x = mp1[str];
			
			if(mp[x].first.size()<=mp[x].second.size())
			{
				cout<<mp[x].first;
			}
			else
			{
				cout<<mp[x].second;
			}
		}
		else if(mp.count(mp2[str])!=0)
		{
			//cout<<"2 ";
			int x = mp2[str];
			
			if(mp[x].first.size()<=mp[x].second.size())
			{
				cout<<mp[x].first;
			}
			else
			{
				cout<<mp[x].second;
			}
		}
	}
	printf("\n");
	
	return 0;
}
