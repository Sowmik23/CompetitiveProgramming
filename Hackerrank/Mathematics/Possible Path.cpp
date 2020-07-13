#include <bits/stdc++.h>

using namespace std;

//grid reachable problem
//GCD || Divisor


#define ll unsigned long long 

int main(){
	
	int t;
	cin>>t;
	while(t--){
		//int flag=0;
		ll a, b, x, y;
		cin>>a>>b>>x>>y;
		
		/*c = a;
		d = b;
		while(c<=x or d<=y){
			//cout<<c<<" "<<d<<endl;
			if(c<x) c = c+b;
			if(d<y) d = a+d;
			if(c==x and d==y) {
				flag = 1;
				break;
				//cout<<"YES"<<endl;
				//return 0;
			}
			else if(c>x or d>y) {
				flag = 2;
				break;
				//cout<<"NO"<<endl;
				//return 0;
			}
		}
		
		while(flag==0){
			//cout<<c<<" "<<d<<endl;
			if(c>x) c = c-b;
			if(d>y) d = d-a;
			if(c==x and d==y) {
				flag = 3;
				break;
				//cout<<"YES"<<endl;
				//return 0;
			}
			else if(c<x or d<y) {
				flag = 4;
				break;
				//cout<<"NO"<<endl;
				//return 0;
			}
			
		}
		
		if(flag!=0 and flag%2==0) cout<<"NO"<<endl;
		else if(flag%2==1) cout<<"YES"<<endl;
		*/
		
		//main tricks: the gcd of the target point 
		//should be equal to the gcd of the starting point.

		if(a==x and b==y) cout<<"YES"<<endl;
		if(__gcd(a, b) == __gcd(x,y)){
			cout<<"YES"<<endl;
		}
		else cout<<"NO"<<endl;
		
	}
	
	return 0;
}
