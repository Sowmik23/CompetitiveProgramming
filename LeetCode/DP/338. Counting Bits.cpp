class Solution {
public:
    vector<int> countBits(int n) {
       
        /*
        ///approach-01: dp/iterative
        vector<int> res;
        for(int i=0;i<=n;i++){
            if(i==0 or i==1) res.push_back(i);
            else if(i%2==0) res.push_back(res[i/2]);
            else res.push_back(res[i/2]+1);
        }
        return res;
        */
        ///approach-02:
    // So, we start from saving the value of 0 as 0 and 1 as 1.
    // Afterwards, we go on checking if the number is a power of 2, our answer would be 1 in this case.
    // And otherwise, it'd be 1 + the answer of the difference from the just smaller power of 2.
    // For example, for 3 the answer wud be 1 + ans[3-2] = 1 + ans[1] = 2
    // for 6, answer wud be 1 + ans[6-4] = 1+ans[2] = 2


        vector<int> res(n+1);
        int TwoPower = 0;
        for(int i=0;i<=n;i++){
            if(i==0 or i==1) res[i] = i;
            else if(isPowerofTwo(i)) {
                res[i] = 1;
                TwoPower = i;
            }
            else {
                res[i] = 1 + res[i-TwoPower];
            }
        }
        return res;
        
        
        //DP: single pass
        vector<int> res(n+1, 0);
        res[0] = 0;
        for(int i=1;i<=n;i++){
            res[i] = res[i>>1] + (1&i);
        }
        
        return res;
    }
    
private:
    bool isPowerofTwo(int n){
        if(ceil(log2(n))==floor(log2(n))) return true;
        return false;
    }    
};
