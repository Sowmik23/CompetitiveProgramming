#include <bits/stdc++.h>
using namespace std;


/// A balanced ternary number system is a numeral system 
/// which comprises of digits -1, 0 and 1. Since it is inconvenient 
/// to write -1 as a digit, we’ll use letter Z further for this purpose.


/*##Conversion of Decimal to Balanced Ternary system :

1. Convert decimal to ternary number system.
2. Convert ternary to balanced ternary system, using below steps: 
traverse the ternary number, right to left by leaving 0 and 1 as it is
when encounter 2, change it to Z and add +1 to the next digit in iteration.
Some digits may become +3, then replace +3 with 0 and add +1 to next digit in iteration.
complete this process until you convert all the digits.
*/


/// Decimal to balanced ternary
string balancedTernary(int n){
	
	string output = "";
	while(n>0){
		int rem = n%3;
		n/=3;
		if(rem==2) {
			rem = -1;
			n++;
		}
		output = ((rem==0) ? '0' : (rem==1) ? '1' : 'Z') + output;
	}
	return output;
}

int main(){
	
	int n;
	scanf("%d", &n);
	
	cout<<balancedTernary(n)<<endl;
	
	
	return 0;
}
