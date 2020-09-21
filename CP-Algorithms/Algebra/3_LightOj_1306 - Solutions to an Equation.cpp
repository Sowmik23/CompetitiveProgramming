#include <bits/stdc++.h>
using namespace std;

/*
 * for Linear Diophantic equation 
 * 
 * ax + by = c
 * 
 * find number of solutions in given interval
 */

/*
Concept:
Let,
a*x + b*y = c                           [x, y can be found by Extended Euclidean algorithm]
a*x + a*b*t/g - a*b*t/g + b*y = c       [ g = gcd(a, b) ]
a*(x + b*t/g) + b*(y - a*t/g) = c
So,
X = x + b*t/g
Y = y - a*t/g
Now,
x1 <= X <= x2
x1 <= x + b*t/g <= x2
(x1-x)*g/b <= t <= (x2-x)*g/b
y1 <= Y <= y2
y1 <= y - a*t/g <= y2
(y-y1)*g/a <= t <= (y-y2)*g/a
Combining these two, we get,
max( (x1-x)*g/b , (y-y1)*g/a ) <= t <= min( (x2-x)*g/b , (y-y2)*g/a )
*/


typedef long long ll;

ll x, y, d;

void extendedEuclid(ll a, ll b){
	if(b==0){
		x = 1;
		y = 0;
		d = a;
		return ;
	}
	extendedEuclid(b, a%b);
	ll x1, y1;
	x1 = y;
	y1 = x-y*(a/b);
	x = x1;
	y = y1;
	return ;
}



ll find_numberOf_solutions(ll a, ll b, ll c, ll xmin, ll xmax, ll ymin, ll ymax){
	extendedEuclid(a, b);
	
	if(a==0 and b==0){
		if(c) return 0;
		return (xmax - xmin + 1)*(ymax - ymin + 1);
	}
	else if(a==0){
		if(c%b!=0) return 0;
		c = -c/b;
		if(ymin<=c and c<=ymax) return xmax - xmin + 1;
		return 0;
	}
	else if(b==0){
		if(c%a==0) return 0;
		c = -c/a;
		if(xmin<=c and c<=xmax) return ymax - ymin + 1;
		return 0;
	}
	if(c%d==0) {
		x*=(-c/d);
		y*=(-c/d);
		b/=d;
		a/=d;
		swap(a, b);  //x + ka, y - kb
		
		double p = (xmin - x)/(double)a;
		double q = (xmax - x)/(double)a;
		
		if(p>q) swap(p, q);
		xmin = (ll)ceil(p);
		xmax = (ll)floor(q);
		
		p = (y - ymin)/(double)b;
		q = (y - ymax)/(double)b;
		
		if(p>q) swap(p, q);
		ymin = (ll)ceil(p);
		ymax = (ll)floor(q);
		
		//printf("xy(solution) %lld %lld : ab %lld %lld : x(min, max) %lld %lld : y(min, max) %lld %lld\n", x, y, a, b, xmin, xmax, ymin, ymax);
	
		xmin = max(xmin, ymin);
		xmax = min(xmax, ymax);
		
		return max(0LL, xmax - xmin + 1); //0LL is max in long long(ll)
	}
	return 0;
}


int main(){
	
	int t, cs=1;
	cin>>t;
	
	ll a, b, c, xmin, xmax, ymin, ymax;
	while(t--){
		scanf("%lld%lld%lld%lld%lld%lld%lld",&a, &b, &c, &xmin, &xmax, &ymin, &ymax);
		
		
		printf("Case %d:", cs++);
		printf(" %lld\n", find_numberOf_solutions(a, b, c, xmin, xmax, ymin, ymax));
	}
	
	return 0;
}
