#include <bits/stdc++.h>
using namespace std;

///Remember: Recursion takes too much time, so it's not always good
///Space Complexity: O(n) 
///Time Complexity: O(n) (iterative)
///Time Complexity: O(2^n) (recursive)

//recursive solution
int Fib(int n){
	if(n<=1) return n;
	
	return Fib(n-1) + Fib(n-2);
}



//iterative solution
int Fibo(int n){
	if(n<=1) return n;
	int a = 0, b = 1, c;
	for(int i=2;i<=n;i++){
		c = a+b;
		a = b;
		b = c;
	}
	return c;
}
	
	
	

int main(){
	
	int n = 5;
	
	int res;
	res = Fibo(n);
	
	res = Fib(n);
	
	cout<<res<<endl;
	
	return 0;
}
