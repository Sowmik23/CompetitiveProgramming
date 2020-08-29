#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int d, m, y, expected_d, expected_m, expected_y;
	
	int fine = 0;
	cin>>d>>m>>y;
	cin>>expected_d>>expected_m>>expected_y;
	
	if(y<expected_y){
		fine = 0;
	}
	else if(y==expected_y){
		if(m<=expected_m){
			if(d<=expected_d){
				fine = 0;
			}
			else {
				fine = 15*(d-expected_d);
			}
		}
		else {
			fine = 500*(m - expected_m);
		}
	}
	else fine = 10000;
	
	
	cout<<fine<<endl;
	
	return 0;
}
