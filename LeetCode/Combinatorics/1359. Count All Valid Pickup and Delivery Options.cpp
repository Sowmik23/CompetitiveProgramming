class Solution {
public:
    int countOrders(int n) {
        
        //permutations
        //Time: O(n)
        
        long ans = 1;
        int MOD = 1e9+7;
        
        for(int i=1;i<=n;i++){
            //way to arrange all pickups, 1*2*3*4*5*6....*n
            ans = ans*i; 
            //way to arrange all delivers, 1*3*5*7.....*(2*n-1)
            ans = ans*(2*i-1);
            ans%=MOD;
        }
        
        return ans;
    }
};
