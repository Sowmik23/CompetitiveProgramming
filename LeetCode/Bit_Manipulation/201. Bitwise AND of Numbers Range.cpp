class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        
        if(left==0) return 0;
        
        int i=0;
        while(left!=right){
            left >>=1;
            right>>=1;
            i++;
        }
        
        return left<<i;
    }
};
