class Solution {
public:
    bool isPowerOfThree(int n) {
        
        //approach-01: RECURSION
        /*
        if(n<=0) return false;
        
        return ifPowerOfThree(1, n);
        */
        
        //approach-02: bit manipulation
        //first: convert decimal to ternary
        //Time: O(n)
        //Space: O(1)
        
        if(n<=0) return false;
        string ternery="";
        int m = n;
        int x;
        while(m>=3){
            x = m/3;
            ternery=to_string(m%3)+ternery;
            m = x;
        }
        ternery=to_string(m)+ternery;
        //cout<<ternery<<endl;
        
        //find the number of 1 bits
        int cnt_1 = 0;
        int cnt_2 = 0;
        for(int i=0;i<ternery.size();i++){
            if(ternery[i]=='1') cnt_1++;
            else if(ternery[i]=='2') cnt_2++;
        }
        
        //if there is only one bit then it is power of 3
        if(cnt_1==1 and cnt_2==0) return true;
        return false;
    }
private:
    bool ifPowerOfThree(long x, int n){
        if(x==n) return true;
        if(x>n) return false;
        
        return ifPowerOfThree(3*x, n);
    }
};
