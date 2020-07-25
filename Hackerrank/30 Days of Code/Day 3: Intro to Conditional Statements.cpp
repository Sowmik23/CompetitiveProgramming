#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int n;
	cin>>n;
	
	if(n%2!=0) cout<<"Weird"<<endl;
	else if(n%2==0) {
		if(n>=2 and n<=5) cout<<"Not Weird"<<endl;
		else if(n >=6 and n<=20) cout<<"Weird"<<endl;
		else if(n>20) cout<<"Not Weird"<<endl;
	}
	
	
	return 0;
}
