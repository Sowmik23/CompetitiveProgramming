class Solution {
public:
    bool isPowerOfFour(int n) {
        
        //approach: recursive version
        //Time Complexity: O(log4(n))
        //Space Complexity: O(log4(n)) : for recursion stack
        
        //return ifTrue(n, 1);
        
        
        //approach: bit manipulation
       /*
        int andRes;
        int lenOfN;
        
        if(n==0) return false;
        
        if(n==INT_MIN) {
            andRes = n&(n+1); 
            lenOfN = floor(log2(abs(n+1)))+1;
        }
        else {
            andRes = n&(n-1);
            lenOfN = floor(log2(abs(n)))+1;
        }
        
        if(andRes==0 and lenOfN%2==1) return true;
        return false;
        */
        
        //Bit Manipulation: Optimization
        //all negative numbers is not power of 4
        //so actually we just need to check 1 to n
        
        if(n<1) return false;
        int andRes = n&(n-1); //here (n&n-1)==0 means it is power of two
        int lenOfN = floor(log2(n))+1; //1 2 4 8 16 32 64 128 .....-> 2 4 2 4 2 4
        
        if(andRes==0 and lenOfN%2==1) return true;
        return false;
    }
private:
    bool ifTrue(int n, long x){
        if(x==n) return true;
        if(x>n) return false;
        
        return ifTrue(n, x*4);
    }
};
