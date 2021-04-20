#include <bits/stdc++.h>

using namespace std;

///Nice problem :)
/*
dec: switches numbers from hexadecimal back to decimal.
right: aligns values to the right instead of the left
setw(15): sets a fixed width of 15
scientific: Prints output in scientific notation format
uppercase: Undoes previous nouppercase manipulator and ensures that the 'E' in the scientific notation is capitalised
noshowpos: Undoes previous showpos manipulator and gets rid of the plus at the start of positive values
setprecision: Changes the number of digits after the decimal place from 2 to 9.
*/ 



int main(){
	
	int t;
	double A, B, C;
	cin>>t;
	while(t--){
		cin>>A>>B>>C;
		
		//processing a 
		/*
		int x = a;
		stringstream ss;
		ss<<hex<<x;
		string res (ss.str());
		cout<<"0x"<<res<<endl;*/
		
		//or
		cout<<hex<<left<<showbase<<nouppercase;
		cout<<(long long)A<<endl;
		
		//processing b
		cout<<dec<<right<<setw(15)<<setfill('_')<<showpos<<fixed<<setprecision(2);
		cout<<B<<endl;
		
		//processing c
		cout<<scientific<<uppercase<<noshowpos<<setprecision(9);
		cout<<C<<endl;
	}
	
	
	
	return 0;
}
