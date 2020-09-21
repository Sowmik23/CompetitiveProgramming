#include <bits/stdc++.h>
using namespace std;

/*Extended Eucledian algorithm
	ax + by = gcd(a, b)

	problem: given a and b find x, y and gcd(a,b);

	:: we can also determine any one solution of 
	linear diophantine equation by this
	* 
	ax + by = c

*/


int x, y, d;

//recursive implementation
void extendedEuclid(int a, int b){
	if(b==0) {
		x = 1;
		y = 0;
		d = a;
		return;
	 }
	 int x1, y1;
	 extendedEuclid(b, a%b);
	 x1 = y;
	 y1 = x- y*(a/b);
	 x = x1;
	 y = y1;
	 return;
 }

/* 
//iterative version (it's little bit faster)
void extendedEuclid2(int a, int b){
	int x = 1;
	int y = 0;
	int x1 = 0, y1 = 1, a1 = a, b1 = b;
	while(b1){
		int q = a1/b1;
		tie(x, x1) = make_tuple(x1, x-q*x1);
		tie(y, y1) = make_tuple(y1, y-q*y1);
		tie(a1, b1) = make_tuple(b1, a1-q*b1);
	}
	d = a1;
	return;
}
 */
 

int main(){
	
	int a, b;
	cin>>a>>b;
	
	extendedEuclid(a, b);
	
	cout<<x<<" "<<y<<" "<<d<<endl;
	
	return 0;
}
