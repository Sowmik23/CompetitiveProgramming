#include <bits/stdc++.h>

using namespace std;

int main(){
	
	long long n,m, a, b, k, total_candie=0;
	
	cin>>n>>m;
	while(m--){
		cin>>a>>b>>k;
		
		total_candie += (b-a+1)*k;
	}
	//cout<<start<<" "<<end<<" "<<total_candie<<endl;
	long long int ans = total_candie/n;
	cout<<ans<<endl;
	
	return 0;
}
