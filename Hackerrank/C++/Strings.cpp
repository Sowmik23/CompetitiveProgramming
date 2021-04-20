#include <bits/stdc++.h>

using namespace std;


int main(){
	
	string str1, str2;
	
	cin>>str1;
	cin>>str2;
	
	cout<<str1.size()<<" "<<str2.size()<<endl;
	cout<<str1+str2<<endl;
	
	char ch = str1[0];
	str1[0] = str2[0];
	str2[0] = ch;
	
	cout<<str1<<" "<<str2<<endl;
	
	return 0;
}
