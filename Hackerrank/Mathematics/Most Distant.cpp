#include <bits/stdc++.h>

using namespace std;

#define ll long long 

int main(){
	
	ll n, x, y, Px=-10e9, Nx=10e9, Py=-10e9, Ny=10e9;
	cin>>n;
	while(n--){
		cin>>x>>y;
		
		if(x>0){
			Px = max(Px, x);
		}
		if(x<0){
			Nx = min(Nx, x);
		} 
		
		if(y>0){
			Py = max(Py, y);
		}
		if(y<0){
			Ny = min(Ny, y);
		}
	}
	
	cout<<Px<<" "<<Nx<<" " <<Py<<" "<<Ny<<endl;
	
//	if(Px-Nx > Py-Ny) cout<<Px-Nx<<endl;

	cout<<setprecision(12)<<" "<<endl;
	
	
	return 0;
}
