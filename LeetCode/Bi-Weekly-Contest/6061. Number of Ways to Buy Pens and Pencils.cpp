class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        
        long cnt = 0;
        
        for(long i=0;i*cost1<=total;i++){
            long x = (total-(i*cost1))/cost2+1;
            cnt+=x;
        }
        
        return cnt;
    }
};
