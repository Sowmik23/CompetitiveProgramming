#include <bits/stdc++.h>
using namespace std;

//think sorting : nlogn time and without extra space
//think about hashing: O(n) time but O(n) extra space;
//think about bit: O(1) space;


///#####Details about Bitset array

///please must read this link:
/// https://www.geeksforgeeks.org/c-bitset-and-its-application/

/*
A bitset is an array of bool but each Boolean value is not stored separately instead bitset optimizes the space such that each bool takes 1 bit space only, so space taken by bitset bs is less than that of bool bs[N] and vector bs(N). However, a limitation of bitset is, N must be known at compile time, i.e., a constant (this limitation is not there with vector and dynamic array)

As bitset stores the same information in compressed manner the operation on bitset are faster than that of array and vector. We can access each bit of bitset individually with help of array indexing operator [] that is bs[3] shows bit at index 3 of bitset bs just like a simple array. Remember bitset starts its indexing backward that is for 10110, 0 are at 0th and 3rd indices whereas 1 are at 1st 2nd and 4th indices.
We can construct a bitset using integer number as well as binary string via constructors which is shown in below code. The size of bitset is fixed at compile time that is, it can’t be changed at runtime.
The main function defined for bitset class are operator [], count, size, set, reset and many more they are explained in below code:
*/

// C++ program to demonstrate various functionality of bitset
#include <bits/stdc++.h>
using namespace std;

#define M 32

int main()
{

	//cast bitset array to int
	bitset<32> mybit(133);
	 int x = static_cast<int>(mybit.to_ulong()) ;

	 //or
	 int mybit_int = (int)(mybit.to_ulong());



	// default constructor initializes with all bits 0
	bitset<M> bset1;

	// bset2 is initialized with bits of 20
	bitset<M> bset2(20);

	// bset3 is initialized with bits of specified binary string
	bitset<M> bset3(string("1100"));

	// cout prints exact bits representation of bitset
	cout << bset1 << endl; // 00000000000000000000000000000000
	cout << bset2 << endl; // 00000000000000000000000000010100
	cout << bset3 << endl; // 00000000000000000000000000001100
	cout << endl;

	// declaring set8 with capacity of 8 bits

	bitset<8> set8; // 00000000

	// setting first bit (or 6th index)
	set8[1] = 1; // 00000010
	set8[4] = set8[1]; // 00010010
	cout << set8 << endl;

	// count function returns number of set bits in bitset
	int numberof1 = set8.count();

	// size function returns total number of bits in bitset
	// so there difference will give us number of unset(0)
	// bits in bitset
	int numberof0 = set8.size() - numberof1;

	cout << set8 << " has " << numberof1 << " ones and "
		<< numberof0 << " zeros\n";

	// test function return 1 if bit is set else returns 0
	cout << "bool representation of " << set8 << " : ";
	for (int i = 0; i < set8.size(); i++)
		cout << set8.test(i) << " ";

	cout << endl;

	// any function returns true, if atleast 1 bit
	// is set
	if (!set8.any())
		cout << "set8 has no bit set.\n";

	if (!bset1.any())
		cout << "bset1 has no bit set.\n";

	// none function returns true, if none of the bit
	// is set
	if (!bset1.none())
		cout << "bset1 has some bit set\n";

	// bset.set() sets all bits
	cout << set8.set() << endl;

	// bset.set(pos, b) makes bset[pos] = b
	cout << set8.set(4, 0) << endl;

	// bset.set(pos) makes bset[pos] = 1 i.e. default
	// is 1
	cout << set8.set(4) << endl;

	// reset function makes all bits 0
	cout << set8.reset(2) << endl;
	cout << set8.reset() << endl;

	// flip function flips all bits i.e. 1 <-> 0
	// and 0 <-> 1
	cout << set8.flip(2) << endl;
	cout << set8.flip() << endl;

	// Converting decimal number to binary by using bitset
	int num = 100;
	cout << "\nDecimal number: " << num
		<< " Binary equivalent: " << bitset<8>(num);

	return 0;
}


/*
For bitset set, reset and flip function are defined. Set function sets (1) all bits of bitset if no argument is provided otherwise it sets the bit whose position is given as argument. In same way reset and flip also work if they are called with no argument they perform their operation on whole bitset and if some position is provided as argument then they perform operation at that position only.
For bitset all bitwise operator are overloaded that is they can be applied to bitset directly without any casting or conversion, main overloaded operator are &, |, ==, != and shifting operator <> which makes operation on bitset easy.
Use of above operator is shown in below code.
*/
// C++ program to show applicable operator on bitset.
#include <bits/stdc++.h>
using namespace std;

int main()
{
	bitset<4> bset1(9); // bset1 contains 1001
	bitset<4> bset2(3); // bset2 contains 0011

	// comparison operator
	cout << (bset1 == bset2) << endl; // false 0
	cout << (bset1 != bset2) << endl; // true 1

	// bitwise operation and assignment
	cout << (bset1 ^= bset2) << endl; // 1010
	cout << (bset1 &= bset2) << endl; // 0010
	cout << (bset1 |= bset2) << endl; // 0011

	// left and right shifting
	cout << (bset1 <<= 2) << endl; // 1100
	cout << (bset1 >>= 1) << endl; // 0110

	// not operator
	cout << (~bset2) << endl; // 1100

	// bitwise operator
	cout << (bset1 & bset2) << endl; // 0010
	cout << (bset1 | bset2) << endl; // 0111
	cout << (bset1 ^ bset2) << endl; // 0101
}


//Todo: Dynamic Bitset:
// B1 is initialized with size 0
    // with all bits 0
    boost::dynamic_bitset<> B1;

    // B2 is initialized with size
    // bit_size with all bits 0
    boost::dynamic_bitset<> B2(bit_size);

    // B3 is initialized with size
    // bit_size and value 14
    boost::dynamic_bitset<> B3(bit_size, 14);

    // B4 is initialized with size
    // bit_size, value 14 and
    // block_size of 8 bits
    boost::dynamic_bitset<uint8_t> B4(16, 84);




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
	cnt = e;
	for(int i=1;i<=32;i++){
		if((1<<31) & (n>>i)) cnt++;
	}
	cout<<"Total set bits: "<<cnt<<endl;
	cout<<n<<endl;
}




///TODO: 08
//finding next higher and lower number with same number of set bits


///TODO: 09
//optimizing modulus(%) operation: n&(x-1) where n%x;


///TODO: 10
//add 1 to a number without +, | : just determine 2's complement: ~x (~ is bitwise complement). So, -(~x) is the ans

///TODO: 11
Multiply a given Integer with 3.5:

//Time: Space: O(1)
//(x<<3 - x)>>1
//or (x<<1)+x+(x>>1);

	int x = 3;

	cout<<(x<<1)<<endl;
	cout<<(x>>1)<<endl;
	cout<<(x<<1)+x+(x>>1)<<endl;

	//another way:
	cout<<"Another way"<<endl;
	cout<<(x<<3)<<endl;
	int y = (x<<3);
	cout<<y<<endl;
	y-=x;
	cout<<y<<endl;
	cout<<(y>>1)<<endl;

///TODO: 12
//Turn off the rightmost set bit
//Just do n&(n-1)
//Time: Space: O(1)


///TODO: 13
//Find whether a given number is a power of 4 or not
//if it is power of 2: n&(n-1)==1 and find the set bit's position/length. if position/length is odd then true.


///TODO: 14
//Compute the integer absolute value (abs) without branching
//for positive number do nothing but for negative number toggle the bit's then add 1 with it.

//	mask = n>>31 //the leftmost bit/sign bit(it will be 0 for positive and 1 for negative number)

	//now add n with mask: mask + n : So, if the number is negative 1 will be added with the number else 0 will be added

	//then xor n with mask:
	//so if the number is negative then : mask = 1 and n = n+1 , new n = (n+1)^mask
	//else for positive number mask = 0 and n = n new n = n^0 = n

	int const mask = n >> (sizeof(int) * CHARBIT - 1);
    	return ((n + mask) ^ mask);


///TODO: 15
//Compute modulus division by a power-of-2-number
//n%d where d is power of 2

//my initial thought after drawing in paper:  return size of n bit after n xor d

//another solution is : n&(d-1)


///TODO: 16
//Minimum or Maximum of two integers:
//just use bitset array: and iterate from left to right and see if both are negative or both are positive and check bit
//whose bit is 1 and others is 0 is greater and opposite is true of if both numbers are negative


///TODO: 17
//Rotate bits of a number: Think yourself

	cout<<"Rotate bits"<<endl;
	int n = 16;
	int d = 2;

	cout<<((n<<d)|(n>>(8-d)))<<endl;
	cout<<((n>>d)|(n<<(8-d)))<<endl;

//what should you do if you want to rotate the number only, means without 4/8/16/32 bit.
//Easily, You need to rotate the bit's without leading zero



///TODO: 18
//Find the two non-repeating elements in an array of repeating elements/ Unique Numbers 2

//2's complement of x is : -x or ~(x-1) or ~x+1



///TODO: 19
//Find the Number Occurring Odd Number of Times
Given an array of positive integers. All numbers occur an even number of times except one number which occurs an odd number of times. Find the number in O(n) time & constant space.


Do: brute force, hashing, then xor



///TODO: 20
//Check for Integer Overflow
//Write a “C” function, int addOvf(int* result, int a, int b) If there is no overflow, the function places the resultant = sum a+b in “result” and returns 0. Otherwise it returns -1. The solution of casting to long and adding to find detecting the overflow is not allowed.


//Time: O(1), Space: O(1)
=>Sol: There can be overflow only if signs of two numbers are same, and sign of sum is opposite to the signs of numbers.

int sum = a+b;
if(a>0 and b>0 and sum<0) return overflow happened;
if(a<0 and b<0 and sum>0) return overflow happened;
return no overflow happened;





///TODO: 21
//Reverse Bits of a Number
//Time: O(1), Space: O(1)
unsigned int reverseBit(unsigned int number){
	unsigned in res = 0;
	for(int i=0;i<32;i++){
		int bit = 1&(x>>i);
		res = res | bit<<(31-i);
	}
	return res;
}



///TODO: 22
//Smallest power of 2 greater than or equal to n
//5 -> 101 -> 8 -> 1000
//17 -> 10001 -> 100000
//so first check if it is power of of or not :n&(n-1)==0 if  then return this number: , otherwise:
int nextPowerofTwo(int x){
	if(n!=0 and (x&(x-1))==0) return x;
	int len = log2(x)+1;
	//cout<<"len: "<<len<<endl;
	int res = 0;
	res |= 1<<len;

	return res;
}

///TODO: 23
//Efficient Method to Check if a Number is Multiple of 3
//Read again: it's multiple of 3 not power of  3

//If the sum of digits in a number is a multiple of 3 then the number is a multiple of 3,
//e.g., for 612, the sum of digits is 9 so it’s a multiple of 3. But this solution is not efficient.

//Algorithm
// 1) Get count of all set bits at odd positions (For 23 it’s 3).
// 2) Get count of all set bits at even positions (For 23 it’s 1).
// 3) If the difference between the above two counts is a multiple of 3 then the number is also a multiple of 3.



///TODO: 24
// find parity: even or odd parity
int findPairty(int n ){
	int i = 0;
	whille(n){
		if(1&n) cnt++;
		n = n>>i;
		i++;
	}

	return cnt%2==0; //return even parity
}
//efficient way
int findPairty(int n ){
	int parity = 0;
	whille(n){
		parity = !parity;
		n = n&(n-1);
	}

	return parity;
}

// Initialize: n = 13 (1101)   parity = 0
// n = 13 & 12  = 12 (1100)   parity = 1
// n = 12 & 11 = 8  (1000)   parity = 0
// n = 8 & 7 = 0  (0000)    parity = 1


///TODO: 25
///Efficient way to multiply with 7
// First left shift the number by 3 bits (you will get 8n)
// Then subtract the original number from the shifted number
// Return the difference (8n – n).

///vreturn ((n<<3) - n);



///TODO: 26
///Program to find whether a given number is power of 2
1. return (ceil(log2(n)) == floor(log2(n)));
2. count the number of set bits . if count is 1 then it is power of 2;
3. /* First x in the below expression is for the case when x is 0 */
    return x && (!(x&(x-1)));
4. Another way is to use the logic to find the rightmost bit set of a given number:
((n & (~(n - 1))) == n)
5. Brian Kernighan’s algorithm:
return (n != 0) && ((n & (n - 1)) == 0);

///TODO: 27
///Position of rightmost set bit
log2(n & -n) + 1;



///TODO: 28
///Swap all odd and even bits
// 1) Get all even bits of x by doing bitwise and of x with 0xAAAAAAAA. The number 0xAAAAAAAA is a 32 bit number with all even bits set as 1 and all odd bits as 0.
// 2) Get all odd bits of x by doing bitwise and of x with 0x55555555. The number 0x55555555 is a 32 bit number with all odd bits set as 1 and all even bits as 0.
// 3) Right shift all even bits.
// 4) Left shift all odd bits.
// 5) Combine new even and odd bits and return.

// Get all even bits of x
    unsigned int even_bits = x & 0xAAAAAAAA;

    // Get all odd bits of x
    unsigned int odd_bits = x & 0x55555555;

    even_bits >>= 1; // Right shift even bits
    odd_bits <<= 1; // Left shift odd bits

    return (even_bits | odd_bits); // Combine even and odd bits

		

///TODO: 29



///TODO: 30




///TODO: 31



///TODO: 32



///TODO: 33



///TODO: 34

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
