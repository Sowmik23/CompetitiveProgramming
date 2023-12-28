// 1227. Airplane Seat Assignment Probability


class Solution {
public:
    double nthPersonGetsNthSeat(int n) {

        if(n>1) return (double) 1.0/2.0;   
        return 1.0;
    }
};