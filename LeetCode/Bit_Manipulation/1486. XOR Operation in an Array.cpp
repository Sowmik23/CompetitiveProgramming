class Solution {
public:
    int xorOperation(int n, int start) {
        
        // int res = 0;
        int res = start + 2*0;
        for(int i=1;i<n;i++){
            int b = (start+2*i);
            res ^=b;
            // a = b;
        }
        
        return res;
    }
};
