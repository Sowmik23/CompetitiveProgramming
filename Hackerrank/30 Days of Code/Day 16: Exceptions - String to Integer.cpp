#include <bits/stdc++.h>
using namespace std;

int main(){
	string str;
	cin>>str;
	
	int x;
	try{
		x = stoi(str);
		cout<<x<<endl;
	}
	catch(exception x){
		cout<<"Bad String"<<endl;
	}
	
	return 0;
}
