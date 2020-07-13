#include <bits/stdc++.h>
using namespace std;

//The set of divisors of  can be expressed as {1,2,3,4,5,6,12} .
// The divisor whose digits sum to the largest number is 6
// (which, having only one digit, sums to itself). 
//Thus, we print 6 as our answer.

int compute(int x, int y){
	int sum1=0, sum2=0;
	while(x%10){
		sum1+=x%10;
		/*if(sum1>=10){
			int a = sum1%10;
			int b = sum1/=10;
			sum1= a+b;
		}*/
		x/=10;
	}
	while(y%10){
		sum2+=y%10;
		/*if(sum2>=10){
			int c = sum2%10;
			int d = sum2/=10;
			sum2= c+d;
		}*/
		y/=10;
	}
	
	//cout<<sum1<<" "<<sum2<<endl;
	if(sum1==sum2){
		if(x>y) return y;
		else return x;
	}
	if(sum1>sum2) return x;
	else return y;
}

int main()
{
	int n;
	cin>>n;
	
	int ans = 0, res;
	for(int i=1;i<=n;i++){
		if(n%i==0){
			int x = n/i;
			int sum1=0;
			
			while(x%10){
				sum1+=x%10;
				/*if(sum1>=10){
					int a = sum1%10;
					int b = sum1/=10;
					sum1= a+b;
				}*/
				x/=10;
			}
			if(ans==sum1){
				if(res>n/i) {
					res = n/i;
				}
			}
			if(ans<sum1) {
				ans = sum1;
				res = n/i;
			}
		}
	}
	
	cout<<res<<endl;
	
	return 0;
}
