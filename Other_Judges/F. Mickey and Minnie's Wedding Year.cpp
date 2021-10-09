#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int n;
	scanf("%d", &n);
	
	if(n==1){
		cout<<2<<endl;
	}
	else if(n==0 or n==6 or n==9){
		cout<<6<<endl;
	}
	else if(n==7){
		cout<<3<<endl;
	}
	else if(n==2 or n==3 or n==5){
		cout<<5<<endl;
	}
	else if(n==4){
		cout<<4<<endl;
	}
	else if(n==8) cout<<7<<endl;
	
	return 0;
}
