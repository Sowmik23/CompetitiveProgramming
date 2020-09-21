#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
	if(b==0) return a;
	return gcd(b, a%b);
}

/*
 * theory : there exist any solution if c is divisible by gcd(a, b)
 * 
 * otherwise there is no solution
 */


int main(){
	
	int t;
	cin>>t;
	int a, b, c;
	for(int test=1;test<=t;test++) {
		cin>>a>>b>>c;
		
		int x = gcd(a, b);
		
		if(c%x==0) cout<<"Case "<<test<<": Yes"<<endl;
		else cout<<"Case "<<test<<": No"<<endl;
	}
	
	
	return 0;
}
