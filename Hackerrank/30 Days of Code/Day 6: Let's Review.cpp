#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int t;
	cin>>t;
	string str, str1, str2;
	while(t--){
		cin>>str;
		
		str1 = "";
		str2 = "";
		int len = str.size();
		for(int i=0;i<len;i++){
			if(i%2==0) str1+=str[i];
			else str2+=str[i];
		}
		cout<<str1<<" "<<str2<<endl;
	}
	
	return 0;
}
