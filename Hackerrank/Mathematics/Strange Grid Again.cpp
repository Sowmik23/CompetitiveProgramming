#include <bits/stdc++.h>

using namespace std;

//grid problem

/*
In C++, long may or may not work, 
* depending on how your compiler interprets it. 
* To be safe, use int64_t or uint64_t, which makes 
* the size explicit. The definitions of 
* short, int, and long are fuzzy.
*/


int main(){
	
	long long r, c;
	cin>>r>>c;
	
	long long ans ;
	if(r%2==0){
		ans = (r-1)*5 - 5 + (c+ c -1);
	}
	else {
		ans = r*5 - 5 + (c+ c -2);
	}
	
	cout<<ans<<endl;
	
	return 0;
}
