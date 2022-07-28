#include <bits/stdc++.h>
using namespace std;


int main(){
	
	string str = "aa";
	//regex rexExpr("/^(a-z)(.*)\1$/"); 
	regex rexExpr("/^([ab])[ab]*\1$|^[ab]$/"); 
	
	if(regex_match(str, rexExpr)){
		cout<<"True"<<endl;
	}
	else cout<<"False"<<endl;
	
	return 0;
}
