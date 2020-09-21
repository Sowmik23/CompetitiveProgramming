#include <bits/stdc++.h>
using namespace std;

void getSum(string str){
	
	int sum = 0;
	int len = str.size();
	for(int i=0;i<len;i++){
		int x = str[i] - '0';
		sum+=x;
	}
	cout<<sum<<endl;
}


int main(){
	
	int n;
	string str;
	cin>>n;
	while(n--){
		cin>>str;
			
		getSum(str);
	}
	
	return 0;
}



