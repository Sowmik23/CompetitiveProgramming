class Solution {
public:
    bool canWinNim(int n) {
        if(n%4==0) return false;
        else if(n%4==1) return true;
        else if(n%4==2) return true;
        else  return true;
    }
};

//any one can get at least 1/2/3 
