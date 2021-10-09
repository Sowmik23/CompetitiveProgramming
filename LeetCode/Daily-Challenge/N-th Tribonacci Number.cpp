class Solution {
public:
    int tribonacci(int n) {
        
        if(n==0) return 0;
        else if(n==1 or n==2) return 1;
        int a = 0 ;
        int b = 1;
        int c = 1;
        int d; 
        
        while(n>2){
            d = a+b+c;
            a = b;
            b = c;
            c = d;
            n--;
        }
        
        return d;
    }
};
