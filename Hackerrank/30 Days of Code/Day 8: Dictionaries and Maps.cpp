#include <bits/stdc++.h>
using namespace std;

int main(){
	
	map<string, string> mymap;
	int n;
	string x, y;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x;
		cin>>y;
		mymap[x]=y;
	}
	string name;
	while(cin>>name) {
		if(mymap[name].begin()==mymap[name].end()) cout<<"Not found"<<endl;
		else cout<<name<<"="<<mymap[name]<<endl;
	}
	
	return 0;
}
