#include <bits/stdc++.h>
using namespace std;


int main(){
	
	int q, type, score;
	string name;
	
	map<string, int> mp;
	
	cin>>q;
	while(q--){
		cin>>type;
		if(type==1){
			cin>>name>>score;
			mp[name] += score;
		}
		else if (type==2){
			cin>>name;
			mp.erase(name);
			
		}
		else if(type==3){
			cin>>name;
			if(mp.find(name)!=mp.end()) cout<<mp[name]<<endl;
			else cout<<0<<endl;
		}
	}
	
	
	return 0;
}
