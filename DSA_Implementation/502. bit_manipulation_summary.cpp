#include <bits/stdc++.h>
using namespace std;

//think sorting : nlogn time and without extra space
//think about hashing: O(n) time but O(n) extra space;
//think about bit: O(1) space;


///#####Details about Bitset array

///please must read this link:
/// https://www.geeksforgeeks.org/c-bitset-and-its-application/

///Example
/*
	string s1,s2;
	cin>>s1>>s2;

	//Declaration for bitset type variables
	bitset<26> b_s1,b_s2;

	// setting the bits in b_s1 for the encountered characters of string s1 
	for(auto& i : s1)
	{
	  if(!b_s1[i-'a'])
		b_s1[i-'a'] = 1;
	}

	// setting the bits in b_s2 for the encountered characters of string s2 
	for(auto& i : s2)
	{
	  if(!b_s2[i-'a'])
		b_s2[i-'a'] = 1;
	}

   // counting the number of set bits by the "Logical AND"  operation
   // between b_s1 and b_s2
   cout<<(b_s1&b_s2).count(); 
*/



///TODO: 00
/*
 * Swap two numbers without using extra vairiable
 */
void swapTwoNumber(int a, int b){
	cout<<"Before swap: "<<a<<" "<<b<<endl;
	
	if(a==b) return;
	
	a = a xor b;
	b = a xor b;
	a = a xor b;
	
	cout<<"After swap: "<<a<<" "<<b<<endl;
}







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
 
 
 
 
 
 
 
 
/// TODO: 03
 /*
  Given a positive integer n, count the total number of set bits in 
  * binary representation of all numbers from 1 to n.
  */
/// Size of integer is 32 bit.
/// Time: O(1)
/// Space: O(1)
int cntTotalSetBit(int x){
	int cnt = 0;
	for(int i=32;i>0;i--){
		if(1&(x>>i)) cnt++;
	}
	return cnt;
}
//approach: recursive
int cntTotalSetBitRecursive(int x){
	if(x<=0) return 0;
	if(x%2==1) return 1+cntTotalSetBitRecursive(x/2);
	return cntTotalSetBitRecursive(x/2);
}
//approch: dp: count the set bits from 1 to n
int countSetBitsDP(int n){
	vector<int> setBits(n+1);
	
	//there is not setBit in 0
	setBits[0] = 0;
	int cnt = 0;
	
	for(int i=1;i<=n;i++){
		//cout<<i<<" "<<(i>>1)<<endl;
		setBits[i] = setBits[i>>1] + (1&i); //i>>1 means i is divided by 2
		cnt+=setBits[i];
	}
	
	return cnt;
}
//stl
int count = __builtin_popcount(4);
 
 
 
 
 
 
 
 

 /// TODO: 04 =>Hard
 /*
  Given a number x and two positions (from the right side) in 
  * the binary representation of x, write a function that swaps
  * n bits at given two positions and returns the result.
  * It is also given that the two sets of bits do not overlap.
  */
/// Size of integer is 32 bit.
/// Time: O(1)
/// Space: O(1)

 
 
 
 
 
 
 
/// TODO: 05
/*
 * Add two numbers without using arithmetic operators
 * Bit shifting basics: https://www.youtube.com/watch?v=qq64FrA2UXQ
 * Start watching this video from 13 min
 */
 void addTwoNumbers(int a, int b){
	 ///need to use 3 logical operators only(xor, and and left shift)
	 cout<<"Sum of "<<a<<" and "<<b<<" is: ";
	 int carry = (a & b); //use unsigned carry
	 
	 while(b){
		 a = a ^ b;
		 
		 b = (carry<<1);
		 
		 carry = (a & b);
	 }
	 cout<<a<<endl;
 }
 
 
 
 
 
 
 
 
 
/// TODO: 06
 /*
  Smallest of three integers without comparison operators
  */
/// Size of integer is 32 bit.
/// Time: O(1)
/// Space: O(1)
//approach-01: Repeated substraction/Math
//approach-02: Bit approach:

///first find smallest of two number without use ">" and "<" 
void smallestOfTwo(int a, int b){
	
	int smallest; 
	int x = a;
	int y = b;
	for(int i=31;i>=0;i--){
		int sa = 1&(a>>i);
		int sb = 1&(b>>i);
		
		if(i==31){
			cout<<"Sign bit: "<<sa<<" "<<sb<<endl;
			if(sa==1 and sb==0){
				smallest = x;
				break;
			}
			else if(sa==0 and sb==1){
				smallest = y;
				break;
			}
		}
		cout<<"Other bits: "<<sa<<" "<<sb<<endl;
		
		if(sa==sb) continue;
		if(sa==1 and sb==0){
			smallest = y;
			break;
		}
		else if(sa==0 and sb==1){
			smallest = x;
			break;
		}
	}
 
	cout<<"Smallest is: "<<smallest<<endl;
}

///This method shifts the subtraction of x and y by 31 (if size of integer 
///is 32). If (x-y) is smaller than 0, then (x -y)>>31 will be 1. 
///If (x-y) is greater than or equal to 0, then (x -y)>>31 will be 0. 
///So if x >= y, we get minimum as y + (x-y)&0 which is y. 
///If x < y, we get minimum as y + (x-y)&1 which is x.
///Similarly, to find the maximum use 
///x - ((x - y) & ((x - y) >> (sizeof(int) * CHAR_BIT - 1))) 
void smallestofTwo2(int a, int b){
	
	int smallest = b + ((a - b)&((a - b)>>31));

	cout<<"Smallest between "<<a<<" and "<<b<<" is: "<<smallest<<endl; 
 
	int greatest = a - ((a - b) & ((a - b)>>31));
	cout<<"Greatest between "<<a<<" and "<<b<<" is: "<<greatest<<endl; 

	//same as
	int smlest = b^((a^b) & -(a < b));
	cout<<smlest<<endl;
	int grtest = a^((a^b) & -(a<b));
	cout<<grtest<<endl; 
	
	///It works because if x < y, then -(x < y) will be -1 which is 
	///all ones(11111….), so r = y ^ ((x ^ y) & (111111…)) 
	///= y ^ x ^ y = x. 

    ///And if x>y, then-(x<y) will be -(0) i.e -(zero) which is zero, 
    ///so r = y^((x^y) & 0) = y^0 = y.
 }
 
 
 
 
 
	
///TODO: 07
/*
 * Count set bits in an integer
 */
void countSetBits1(int n){
	int cnt = 0;
	for(int i=31;i>=0;i--){
		if(1&(n>>i)) cnt++;
	}
	cout<<"Total set bits: "<<cnt<<endl;
	
	cout<<n<<endl;
	
	
	////approach-02;
	cnt = 0;
	int mask = 1;
	for(int i=0;i<32;i++){
		if(mask & n) cnt++;
		mask = mask<<1;
	}
	cout<<"Total set bits: "<<cnt<<endl;
	cout<<n<<endl;
	
	
	////approach-03:
	cnt = 0;
	for(int i=1;i<=32;i++){
		if((1<<31) & (n>>i)) cnt++;
	}
	cout<<"Total set bits: "<<cnt<<endl;
	cout<<n<<endl;
}




///TODO: 08



///TODO: 09



///TODO: 10


///TODO: 11
	
 
/// TODO: Extra
/*
 * Divide two integers without using multiplication, division, and 
 * mod operator.
 */
 int divide(int dividend, int divisor) {
     
        if(dividend==divisor) return 1;
       
        bool isPositive = (dividend<0 == divisor<0);
        unsigned int a = abs(dividend);
        unsigned int b = abs(divisor);
        
        unsigned int ans = 0;
        
        while(a>=b){
            short q = 0 ;
            while(a>(b<<(q+1))){
                q++;
            }
            
            a = a-(b<<q);
            ans += (1<< q);
        }
        
        if(ans==INT_MIN and isPositive) return INT_MAX;
        
        return isPositive? ans : -ans;
	}
 
 
 


int main(){
/*	
	//00
	swapTwoNumber(2, 3);

	//01
	vector<int> nums = {3, 3, 3, 2, 4, 4, 4, 5, 5, 5};
	findUniqueElement(nums);
	
	//02
	if(checkSignedBit(-2, 4)==true) cout<<"Oposite sign"<<endl;
	else cout<<"Same sign"<<endl;
	
	//03
	int cnt = 0;
	for(int i=1;i<=8;i++){
		cnt+=cntTotalSetBit(i);
	}
	cout<<cnt<<endl;
	
	cout<<cntTotalSetBitRecursive(16)<<endl;
		
	cout<<countSetBitsDP(6)<<endl;
	*/
	
	
	//04
	
	
	
	//05
	///addTwoNumbers(1, 3);
	
	
	//06
	//smallestOfTwo(-5, -7); //approach-01
	//smallestofTwo2(2, 3); //approach-02
	
	
	
	//07
	countSetBits1(10);
	
	
	//08
	
	
	
	//09
	
	
	
	//10
	
	
	//11
	
	
	


	
	
	return 0;
}
