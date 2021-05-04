class Solution {
public:
    bool isHappy(int n) {
        
        
        int sum = 0, x;
        while(n>9) {
            sum = 0;
            while(n!=0){
                x = n%10;
                x = x*x;
                sum+=x;
                n/=10;
            }
            n = sum;
        }
        if(n==1 or n==7 ) return true; //only square of 1 and 7 results in 1
        return false;
    }
};
