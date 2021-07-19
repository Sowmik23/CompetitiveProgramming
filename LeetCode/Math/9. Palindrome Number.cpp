class Solution {
public:
    bool isPalindrome(int x) {
        
        long long reverseX=0, r;
        int tmp = x;
        
        if(x<0) return false;
        
        while(tmp){
            
            r = tmp%10;
            reverseX = reverseX*10 + r;
            tmp/=10;
        }
        
       // cout<<reverseX<<endl;
        if(reverseX==x) return true;
        else return false;
    }
};
