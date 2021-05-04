class Solution {
public:
    int addDigits(int num) {
        
        //approach-01
        /*int sum = 0;
        while(num>9){ 
            while(num!=0){
                sum+=num%10;
                num/=10;
            }
            num = sum;
            sum = 0;
        }
        return num;*/
        
        //approach-02
        /*int sum = 0;
        while(num>0){
            sum+=num%10;
            num/=10;

            if(num==0 and sum>9){
                num = sum;
                sum = 0;
            }
        }
        return sum;*/
        
        //approah-03: O(1)
        if(num==0) return 0;
        int k =num%9;
        if(k==0) return 9;
        return k;
    }
};
