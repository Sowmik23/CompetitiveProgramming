/// Example, lexicographically next permutation of “gfg” is 
/// “ggf” and next permutation of “acb” is “bac”.


#include <bits/stdc++.h>
using namespace std;


int main(){

/// In C++ there is a function: 
/// next_permutation(a.begin(), a.end()). It returns ‘true’ 
/// if the function could rearrange the object as a 
/// lexicographically greater permutation. Otherwise, 
/// the function returns ‘false’.

	// find next permutation using c++ stl
	string str = "bcda";
	bool nextPerm = next_permutation(str.begin(), str.end());
	if(nextPerm==true) cout<<str<<endl;
	else cout<<"No next permutation is possible"<<endl;

	//also we can generate all permutations using c++ next_permutation stl
	//first of all we need to sort the input string
	sort(str.begin(), str.end());
	while(next_permutation(str.begin(), str.end()){
		cout<<str<<endl;
	}
	
	
/// Now we will see how next_permutation works:
/*
Algorithm:
1. A sequence sorted in decending order doesnot have next permutation. 4321 doesnot have next permutation.

2. For a sequence which is not sorted in descending order, follow the steps: 
	
	a. Traverse from right and find the first item that is not following the descending order."abedc" here b doesn't follow the descending order.
	
	b. Swap the found value with the smallest greater value on it's right side. In case of "abedc" c is the closest greater value. After swapping 'b' and 'c' string becomes "acedb".
	
	c. After swapping, sort the string after the position of character found in step a. After sorting the substring "edb" will be "bde" and we will get "acbde" which is the required next permutation.	 
	
	
##Optimization in step b and c.
	a. Since the sequence is sorted in descending order we can use binary search to find the closest greater element.
	c. reverse the part after the position of character found in step a.
	
*/

	return 0;
}
