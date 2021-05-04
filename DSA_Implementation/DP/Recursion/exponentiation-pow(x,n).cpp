#include <bits/stdc++.h>
using namespace std;


///Time Complexity: O(logn)

int Pow(int x, int n){
	if(n==0) return 1;
	
	else if(n%2==0){
		int y = Pow(x, n/2);
		return y*y;
	}
	else return x*Pow(x, n-1);
}


int main(){
	
	int x = 2 , n = 14;
	
	int res = Pow(x, n);
	cout<<res<<endl;
	
	return 0;
}
