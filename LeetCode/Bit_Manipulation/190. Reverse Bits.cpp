class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
  
        bitset<32> bt(n);
        
        int left{0}, right{31} ;
        
        while(left<right){
            bool tmp = bt[left];
            bt[left++] = bt[right];
            bt[right--] = tmp;
        }
        
        return bt.to_ulong();
    }
};
