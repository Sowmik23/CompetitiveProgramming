#include <bits/stdc++.h>
using namespace std;



int main(){
	
	int n;
	cin>>n;
	
	int cnt = 0;
	
	for(int i=1;i<=n;i++){
		int k = sqrt(i);
		for(int j=1;j<=k;j++){
			if(i%j==0) cnt++;
		}
	}
	cout<<cnt<<endl;
	
	return 0;
}

