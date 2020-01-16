
//###Exclusive Question


#include <bits/stdc++.h>
using namespace std;


int main()
{
	unsigned int i,j;

	i = j = 0;
	
	cout<<(0?1:0)<<endl;
	//cout<<i++<<" "<<++j<<endl;
	//cout<<( i++ > ++j)<<endl;

	i = ( i++ > ++j ) ? i++ : i--;
	
	//i++,i--;
	
	cout<<i<<endl;
	
	return 0;
}


 
