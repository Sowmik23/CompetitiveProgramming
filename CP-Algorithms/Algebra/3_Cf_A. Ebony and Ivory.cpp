#include <bits/stdc++.h>
using namespace std;

/* This problem mainly linear diophantic equation solving
 * 
 * ax + by = c
 * 
 * here mainly we need to check if this equation has
 * any solution or not
 * 
 * check if gcd(a,b)|c
 * 
 * We just have to make one more check to ensure a 
 * positive integral solution.

	Complexity: O(log(min(a, b))
 * 
 */

int gcd(int a, int b){
	if(b==0) return a;
	return gcd(b, a%b);
}


int main(){
	
	int a, b, c;
	cin>>a>>b>>c;
	
	//int x = gcd(a, b);
	
	
	int flag = 0;
	for(int i=0;i<=10000;i++){
		for(int j=0;j<=10000;j++){
			if(a*i + b*j==c) {
				flag = 1;
				break;
			}
		}
		if(flag==1) break;
	}
	
	//if(x==1 and flag==0) cout<<"No"<<endl;
	if(flag==1) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	
	return 0;
}
