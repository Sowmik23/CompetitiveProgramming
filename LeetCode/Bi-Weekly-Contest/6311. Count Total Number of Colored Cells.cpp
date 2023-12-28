// 6311. Count Total Number of Colored Cells

class Solution {
public:
    long long coloredCells(int n) {
        
        long long x = (long long) n*n;
        long long y = (long long) (n-1)*(n-1);
        
        return x+y;
    }
};