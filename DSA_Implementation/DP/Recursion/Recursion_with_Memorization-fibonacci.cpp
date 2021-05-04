#include <bits/stdc++.h>
using namespace std;

///Remember: Recursion takes too much time, so it's not always good


//Recursion with memorization is not as efficient as iterative approach 
//in terms of memory. But it's as good as iterative approach in terms 
//of time with respect to n. 



int visited[51];

//recursive solution
int Fib(int n){
	//if(n<=1) return n;
	
	if(visited[n]!=-1) return visited[n];
	
	visited[n] = Fib(n-1) + Fib(n-2);
	return visited[n];
}		
	

int main(){
	
	for(int i=0;i<51;i++){
		visited[i] = -1;
	}
	visited[0] = 0;
	visited[1] = 1;
	
	int n = 40;
	
	int res;
	
	res = Fib(n);
	
	cout<<res<<endl;
	
	return 0;
}

