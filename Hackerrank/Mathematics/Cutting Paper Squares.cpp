#include <bits/stdc++.h>

using namespace std;

//minimum number of cuts needed to cut the entire paper into 1x1 squares.

int main()
{
	long long n,m;
	cin>>n>>m;
	
	/*int res;		
	if(n==1 and m==1) res = 0;
	else if(n==1 and m>1) res = m-1;
	else if(m==1 and n>1) res = n-1;
	else {
		if(m>n){
			res = m-1 + m*(n-1);
		}
		else res = n-1 + n*(m-1);
	}
	*/
	cout<<m*n-1<<endl;
	
	return 0;
}
