#include <bits/stdc++.h>

using namespace std;


int main(){
	
	int n, q, y;
	cin>>n;
	vector<int> v;
	for(int i=0;i<n;i++){
		cin>>q;
		v.push_back(q);
	}
	
	cin>>q;
	while(q--){
		cin>>y;
		
		int x = lower_bound(v.begin(), v.end(), y)-v.begin();
		
		if(v[x]==y) cout<<"Yes "<<x+1<<endl;
		else cout<<"No "<<x+1<<endl;
	}
	
	
	return 0;
}

