#include <bits/stdc++.h>
using namespace std;

map<string , pair<string,int> >mp;
map<string, pair<string,int> >::iterator it;
vector<string>v1;

int main()
{
	string str,str1;
	
	while(cin>>str)
	{
		if(str=="#") break;
		str1= str;
		transform(str1.begin(),str1.end(),str1.begin(),::toupper); //*this line transform a word into uppercase letter*//
		sort(str1.begin(),str1.end());
		
		mp[str1].first=str;
		mp[str1].second++;
	}
	for(it=mp.begin();it!=mp.end();it++)
	{
		//cout<<it->second.first<<" "<<it->second.second<<endl;
		if(it->second.second==1)
		{
			v1.push_back(it->second.first);
		}
	}
	sort(v1.begin(),v1.end());
	for(int i=0;i<v1.size();i++)
	{
		cout<<v1[i]<<endl;
	}
	
	return 0;
}
