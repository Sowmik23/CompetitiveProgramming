#include<bits/stdc++.h>
using namespace std;

vector<pair<string,int>>v1;
pair<string,int>pa;

int main()
{
	int n;
	string s,str,country;
	
	scanf("%d",&n);
	cin.ignore();
	while(n--)
	{
		getline(cin,str);
		int cnt=0;
		stringstream ss(str);
		ss>>country;
		while(ss>>s)
		{
			cnt++;
		}
		pa = make_pair(country,cnt);
		v1.push_back(pa);
	}
	sort(v1.begin(),v1.end());
	
	vector<pair<string,int>>::iterator it;
	
	for(it=v1.begin();it<=v1.end();it++)
	{
		cout<<it->first<<" "<<it->second<<endl;
	}
	
	
	
	
	return 0;
}
