#include <bits/stdc++.h>
using namespace std;

///using recursion
//Time: O(2^n)
//Space: O(n)
long long fibo(int n){
	if(n<=2) return 1;
	return fibo(n-1)+fibo(n-2);
}


///using recursion with memorization
//Here, Time: O(2*n) = O(n)
//Space: O(n)
long long fiboWithMemorization(int n, vector<long long> &memo){
	if(memo[n]!=-1) return memo[n];
	if(n<=2) return 1;
	memo[n] = fiboWithMemorization(n-1, memo)+fiboWithMemorization(n-2, memo);
	return memo[n];
}



//tabulation method: iterative
//Time: O(n) , Linear
long long fiboTabulation(long long n){
	vector<long long> dp(n+1, 0); ///initialize till n+1
	
	dp[1] = 1;
	for(int i=0;i<=n;i++){
		dp[i+1] += dp[i];
		dp[i+2] += dp[i];
	}
	
	return dp[n];
}


int main(){
	
	cout<<fibo(8)<<endl;
	
	vector<long long> memo(51, -1);
	//cout<<fibo1(21, memo)<<endl;
	cout<<fiboWithMemorization(50, memo)<<endl;
	
	cout<<fiboTabulation(100)<<endl;
	
	
	
	return 0;
}
