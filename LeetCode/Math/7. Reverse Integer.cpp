class Solution {
public:
    int reverse(int x) {
        
        // if(x==0) return 0;
        // int len = log10(abs(x));
        // if(len>=9) return 0;
        // // cout<<len<<endl;
        // int i=len, digit = 0,d ;
        // bool flag = false;
        // if(x<0){
        //     flag = true;
        //     x = abs(x);
        // }
        
        int digit = 0, d;
        while(x!=0){
            d = x%10;
            x/=10;
            
            if(digit>INT_MAX/10 or digit==INT_MAX and d>7) return 0; //INT_MAX is +2147483647 and last digit is 7
            if(digit<INT_MIN/10 or digit==INT_MIN and d<-8) return 0; //INT_MIN is -2147483648 and last digit is 8
            
            digit = digit*10 + d;
        }
        
        return digit;
    }
};
