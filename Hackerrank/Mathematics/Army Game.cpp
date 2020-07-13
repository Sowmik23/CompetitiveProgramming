#include <bits/stdc++.h>
using namespace std;

//minimum number of supply packages Luke must drop.
int main(){
	
	int n,m,res;
	scanf("%d%d",&n,&m);
	
	if(m==1){
		res = (n+1)/2;
	}
	else if(n==1){
		res = (m+1)/2;
	}
	else {
		int a = (m+1)/2;
		int b = (n+1)/2;
		res = a*b;
	}
	printf("%d\n",res);
	
	return 0;
}
