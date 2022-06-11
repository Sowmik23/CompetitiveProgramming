class Solution {
public:
    int divide(int dividend, int divisor) {
     
        if(dividend==divisor) return 1;
       
        bool isPositive = (dividend<0 == divisor<0);
        unsigned int a = abs(dividend);
        unsigned int b = abs(divisor);
        
        unsigned int ans = 0;
        
        while(a>=b){
            short q = 0 ;
            while(a>(b<<(q+1))){
                q++;
            }
            
            a = a-(b<<q);
            ans += (1<< q);
        }
        
        if(ans==INT_MIN and isPositive) return INT_MAX;
        
        return isPositive? ans : -ans;
    }
};
