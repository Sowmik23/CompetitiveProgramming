#include <bits/stdc++.h>

using namespace std;

int main(){
	
	int t;
	cin>>t;
	
	
	while(t--){
		
		char str[105];
		string str2;
		
		cin>>str;
		int len = strlen(str);
		int i;
		for( i=0;i<len;i+=2){
			str2+=str[i];	
			
		}
		if(i!=len-1) str2+=str[len-1];
		
		cout<<str2<<endl;
	}
	
	
	return 0;
}
