#include <bits/stdc++.h>
using namespace std;


int main(){
	int n;
	int r1, s1, p1;
	int r2, s2, p2;
	
	cin>>n;
	cin>>r1>>s1>>p1;
	cin>>r2>>s2>>p2;
	
	int mx = min(r1, s2) + min(s1, p2) + min(p1, r2);
	int mn = min(r1, n-s2) + min(s1, n-p2) + min(p1, n-r2);
	
	cout<<n-mn<<" "<<mx<<endl;
	
	
	
	return 0;
}
