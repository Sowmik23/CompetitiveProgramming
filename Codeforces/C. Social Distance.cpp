#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n, k;
		cin>>n>>k;
		
		char c;
		int cnt=k;
		int res=0;
		for(int i=0;i<n;i++){
			cin>>c;
			if(c=='0') cnt++;
			if(c=='1') {
				cnt-=k;
				res+=cnt/(k+1);
				cnt=0;
			}
		}
		res+=(cnt/(k+1));
				
		
		cout<<res<<endl;
		
	}
	return 0;
}
