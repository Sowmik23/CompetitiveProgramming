#include <bits/stdc++.h>
using namespace std;


int main(){
	
	int t;
	cin>>t;
	
	int n, m, x1, y1, x2, y2;
	
	while(t--){
		cin>>n>>m;
		
		bool flag = false;
		for(int i=0;i<n;i++){
			cin>>x1>>y1;
			cin>>x2>>y2;
			
			if(x2==y1) flag = true;
		}
		
		if(m%2!=0 or flag==false) cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
		
	}
	
	return 0;
}
