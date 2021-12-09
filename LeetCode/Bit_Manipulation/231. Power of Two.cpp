class Solution {
public:
    bool isPowerOfTwo(int n) {
        
        if(n==0) return false;
        if(n==-2147483648) return false; //or if(n==INT_MIN) return false;
        return !(n&(n-1));
    }
};
