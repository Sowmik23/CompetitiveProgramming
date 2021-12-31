class Solution {
public:
    int bitwiseComplement(int n) {
        
        //check every bit of num by xor'ing with appropriate power of 2
        
        if(n==0) return 1;
        for(long i=1;i<=n;i*=2){
            n^=i;
        }
        
        return n;
    }
};
