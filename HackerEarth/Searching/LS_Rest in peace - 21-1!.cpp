#include <bits/stdc++.h>
using namespace std;


int main(){
	
	int t, n;
	cin>>t;
	while(t--){
		cin>>n;
		int x = n;
		//cout<<n%21<<endl;
		bool f = false;
		while(n!=0){
			int k = n%10;
			n/=10;
			int l = n%10;
			if(k==1 and l==2){
				f = true;
				break;
			}
		}
		if(x%21==0 or f==true) cout<<"The streak is broken!"<<endl;
		else cout<<"The streak lives still in our heart!"<<endl;
	}
	
	return 0;
}
