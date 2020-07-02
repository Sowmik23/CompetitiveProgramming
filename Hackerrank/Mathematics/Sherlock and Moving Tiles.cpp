#include <bits/stdc++.h>

using namespace std;

int main(){
	
	long long L, S1, S2, q, area; 
	double t;
	
	cin>>L>>S1>>S2;
	cin>>q;
	while(q--){
		cin>>area;
		
		t = sqrt(2)*abs(sqrt(area) - L)/abs(S2-S1);
		
		cout<<setprecision(50)<<t<<endl;
	}
	
	return 0;
}
