//Legendre’s formula 
//(Given p and n, 
//find the largest x such that p^x divides n!)

#include <bits/stdc++.h>
using namespace std;



int largestPower(int n, int p){
	int res = 0;
	
	//calculate res = n/p + n/(p^2) + n/(p^3) +.....
	while(n){
		n/=p;
		res+=n;
	}
	return res;
}


int main(){
	int p, n;
	cin>>p>>n;
	
	cout<<largestPower(n, p)<<endl;
	
	return 0;
}
