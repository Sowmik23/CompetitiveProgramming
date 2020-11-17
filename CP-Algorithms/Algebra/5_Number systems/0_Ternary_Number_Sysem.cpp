#include <bits/stdc++.h>
using namespace std;

/// If the Base value of a number system is 3, then this 
/// representation is known as a ternary representation. 
/// The digits in this system are 0, 1, and 2.


/// ###Steps to Convert Decimal to Ternary:
/*
Divide the number by 3.
Get the integer quotient for the next iteration.
Get the remainder for the ternary digit.
Repeat the steps until the quotient is equal to 0.
*/


void decimalToTernary(int n){
	
	if(n==0) return ;
	
	int x = n%3;
	n/=3;
	
	if(x<0) n+=1;
	
	decimalToTernary(n);
	
	//handling negative cases
	if(x<0) cout<<x+(3*-1);
	else cout<<x;
}

void TernaryToDecimal(int n){
	int decimalNumber = 0;
	if(n!=0) {
		int i=0, remainder;
		while(n!=0) {
			remainder = n%10;
			n/=10;
			
			decimalNumber += remainder*pow(3, i);
			i++;
		}
	}
	cout<<decimalNumber<<endl;
}


int main(){
	
	int n;
	scanf("%d", &n);
	
	
	if(n!=0) {
		decimalToTernary(n); 
		cout<<endl;
	}
	else cout<<"0"<<endl;
	
	TernaryToDecimal(10202202);
	
	return 0;
}
