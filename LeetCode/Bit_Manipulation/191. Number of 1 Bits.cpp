class Solution {
public:
    int hammingWeight(uint32_t n) {
        
        bitset<32> bt(n);
        int left{0}, right{31};
        
        int cnt = 0;
        while(left<=right){
            if(bt[left++]&1) cnt++;
        }
        return cnt;
    }
};




class Solution {
public:
    int hammingWeight(uint32_t n) {
        
        int cnt = 0;
        while(n){
            if(1&n) cnt++;
            n = n>>1;
        }
        
        return cnt;
    }
};
