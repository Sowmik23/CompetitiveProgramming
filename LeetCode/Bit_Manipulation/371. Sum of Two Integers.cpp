371. Sum of Two Integers
class Solution {
public:
    int getSum(int a, int b) {
        
        //use 3 logical operators only(xor, and, and left shift)

        //return b==0? a:getSum(a^b, (a&b&0xFFFFFFFF)<<1); //&0xFFFFFFFF is for handling negative number
        //same as :return b==0?a:getSum(a^b,(unsigned int)(a&b)<<1);

        unsigned int x = b;
        unsigned int carry = a&x;
        while(x){
            a = a^x;
            x = carry<<1;

            carry = a&x;
        }
        return a;
    }
};