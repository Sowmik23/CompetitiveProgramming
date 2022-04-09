#include <bits/stdc++.h>
using namespace std;

//think sorting : nlogn time and without extra space
//think about hashing: O(n) time but O(n) extra space;
//think about bit: O(1) space;


///TODO: 01
/*
Given an array where every element occurs three times, 
* except one element which occurs only once. Find the element that 
* occurs once. The expected time complexity is O(n) and O(1) 
* extra space.
*/
/// Size of integer is 32 bit.
/// Time: O(C*n) // C is size of integer: 32 (constant), n= size of nums array
/// Space: O(1)
int findUniqueElement(vector<int> &nums){
  
	string res = "";
	for(int i=31;i>=0;i--){
		int cnt = 0;
		for(int j=0;j<(int)nums.size();j++){
			///check the i'th bit
		  	if((1&(nums[j]>>i))==1) cnt++;
		}
		if(cnt%3==1) res+="1";
		else res+="0";
	}
	///cout<<res<<endl;
	//convert res into decimal number
	cout<<stoi(res, 0, 2)<<endl;
	
	
	return stoi(res, 0, 2);
}


///TODO: 02
/*
 Given two signed integers, write a function that returns true if the
 signs of given integers are different, otherwise false. For example, 
 the function should return true -1 and +100, and should return false
 for -100 and -200. The function should not use any of the arithmetic
 operators.  
 */
 /// Size of integer is 32 bit.
 /// Time: O(1)
 /// Space: O(1)
 bool checkSignedBit(int x, int y){
	 ///the xor of opposite sign value will always negative
	 ///-1 = 1|001
	 /// 4 = 0|100
	 ///------------
	 ///-5 = 1|101
	 ///cout<<(x^y)<<endl;
	// return (x^y)<0;
	 
	 ///as comparison takes more time so another way is directly
	 ///check the Msb. right shift 31 bit and check last bit(32th) only.
	 ///if the msb is 1 then opposite sign else same sign.
	 return ((x^y)>>31); //faster than previous
 }
 
 
 
 


int main(){
	
	//01
	vector<int> nums = {3, 3, 3, 2, 4, 4, 4, 5, 5, 5};
	findUniqueElement(nums);
	
	//02
	if(checkSignedBit(-2, 4)==true) cout<<"Oposite sign"<<endl;
	else cout<<"Same sign"<<endl;
	
	
	
	
	
	return 0;
}
