#include <bits/stdc++.h>

using namespace std;


int main(){
	
	int q, x, y;
	cin>>q;
	set<int> s;
	set<int>::iterator it;
	
	while(q--){
		cin>>y>>x;
		if(y==1){
			s.insert(x);
		}
		else if (y==2){
			it = s.find(x);
			//cout<<*it<<endl;
			//if(*it==x) s.erase(x);
			if(it!=s.end()) s.erase(x);
		}
		else if(y==3){
			it = s.find(x);
			if(it!=s.end()) cout<<"Yes"<<endl;
			else cout<<"No"<<endl;
		}
	}
	
	
	return 0;
}
