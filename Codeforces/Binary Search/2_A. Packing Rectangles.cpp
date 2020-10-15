#include <bits/stdc++.h>
using namespace std;

/// https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/A
/// Category: Binary Search(Application-step:02


///###Attention this problem is very sensitive to
/// overflow. Beacuse of overflow I need to suffer a
/// lot.

typedef unsigned long long ll;
const ll MAX = 1e18;
ll w, h, n;



void BinarySearch(ll w, ll h, ll n){
	ll low = 0, high = MAX;
	ll k;
	ll mid;
	ll res=	MAX;
	while(low<=high){
		mid = (low+high)/2;
		
		k = (mid/w)*(mid/h);
		//cout<<mid/w<<" "<<mid/h<<endl;
		if(k>=n) {
			high = mid-1;
			res = mid;
		}
		else  low = mid+1;
	}
	cout<<res<<endl;
}



int main(){
	
	cin>>w>>h>>n;
	
	BinarySearch(w, h, n);
	
	
	return 0;
}
