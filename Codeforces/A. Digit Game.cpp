#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int t, n;
	cin>>t;
	while(t--){
		cin>>n;
		string str;
		cin>>str;
		
		int cnt1=0, cnt2=0;
		
		for(int i=0;i<n;i++){
			if(i%2==0){ //odd position
				int x = str[i]-'0';
				//cout<<x<<endl;
				if(x%2!=0) cnt1++; //odd number
			}
			else { //even position
				int x = str[i]-'0';
				//cout<<x<<endl;
				if(x%2==0) cnt2++; //even number
			}
		}
		//cout<<cnt1<<" "<<cnt2<<endl;
			
		if(n%2!=0){
			if(cnt1>0) cout<<"1"<<endl;
			else cout<<"2"<<endl;
		}
		else {
			if(cnt2>0) cout<<"2"<<endl;
			else cout<<"1"<<endl;
		}
	}
	
	
	return 0;
}
