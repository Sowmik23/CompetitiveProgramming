#include <bits/stdc++.h>
using namespace std;

vector<string>v1;

string comp(string s)
{
	/* this line Remove all empty space */
	s.erase(remove(s.begin(),s.end(),' '),s.end());   
	sort(s.begin(),s.end());                     /* sort the string */
	return s;
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);

	int t;
	scanf("%d",&t);
	string str;
	
	cin.ignore();
	cin.ignore();
	
	for(int k=1;k<=t;k++)
	{
		v1.clear();
		
		while(getline(cin,str))
		{
			if(str=="") break;
			v1.push_back(str);
		}
		int l=v1.size();
		sort( v1.begin(),v1.end());
		
		//if(k!=1 or k!=t )  cout<<endl; 

  //space er problem 
		for(int i=0;i<l;i++)
		{
			for(int j=i+1;j<l;j++)
			{
				if(comp(v1[i])==comp(v1[j]))
				{
					cout<<v1[i]<<" = "<<v1[j]<<endl;
				}
			} 
		} 
	}
	
	return 0;
}
