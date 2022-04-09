/// Using stringstream class or sscanf()


#include <bits/stdc++.h>
using namespace std;


int main(){

/// A stringstream is similar to input/output file stream. We 
/// need to declare a stringstream just like an fstream
	
	string s = "1234324";
	stringstream ss;
	int val = 0;
	
	ss>>val;
	
	cout<<val<<endl;


/// sscanf() is a C style function similar to scanf(). It 
/// reads input from a string rather that standard input. 

	const char *str = "12345";
    int x;
    sscanf(str, "%d", &x);
    printf("\nThe value of x : %d", x);


/// stoi() : The stoi() function takes a string as an argument 
/// and returns its value.

	string str3 = "31337 geek";

    int myint3 = stoi(str3);
    cout<<myint3<<endl;
    
/// atoi() : The atoi() function takes a character array or 
/// string literal as an argument and returns its value.
    
    
    const char* str4 = "31337 geek";

    int num3 = atoi(str4);
	cout<<num3<<endl;
	
	
// atoi() works only for C-style strings (character array and string literal), 
// stoi() works for both C++ strings and C style strings
// atoi() takes only one parameter and returns integer value.


//converting binary string to decimal/hexadecimal/octal using stoi()
//stoi() is awesome

string num="10101110";
cout<<stoi(num, 0, 2)<<endl;
cout<<stoi(num, 0, 10)<<endl;
cout<<stoi(num, 0, 16)<<endl;
cout<<stoi(num, 0, 8)<<endl;

	
	    
	return 0;
}
