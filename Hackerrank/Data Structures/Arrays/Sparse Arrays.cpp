#include <bits/stdc++.h>
using namespace std;

int main()
{
	map<string, int> res;
	int n, q;
	cin>>n;
	string str[n];
	for(int i=0;i<n;i++) {
		cin>>str[i];
		res[str[i]]++;
	}
	
	cin>>q;
	
	string x;
	
	for(int i=0;i<q;i++){
		cin>>x;
		
		cout<<res[x]<<endl;
	}
	
	
	return 0;
}
