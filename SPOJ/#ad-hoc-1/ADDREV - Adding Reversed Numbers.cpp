#include <bits/stdc++.h>
using namespace std;


int reverse(int number){
	
	int x, y=0;
	while(number>0) {
		x = number%10;
		y = y*10 + x;
		number = number/10;
	}
	
	return y;
}


int main(){
	
	int n;
	cin>>n;
	
	int a, b;
	while(n--){
		
		cin>>a>>b;
		
		int a1 = reverse(a);
		int b1 = reverse(b);
		int k = a1 + b1;
		cout<<reverse(k)<<endl;
	}

	
	
	
	return 0;
}
