#include <bits/stdc++.h>

using namespace std;

//average number of candies across n jars,
// rounded down to the nearest integer.

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
