class Solution {
public:
    int getMaximumGenerated(int n) {
        
    
        if(n<=1) return n;
        else if(n==2) return 1;
        vector<int> memo(n+2);
        int mx = 0;
        
        memo[0] = 0;
        memo[1] = 1;
        
        mx = max(memo[0], memo[1]);
        
        for(int i=0;i<=n/2+2;i++){
            if(2*i<=n) memo[2*i] = memo[i];
            if(2*i<=n) mx = max(mx, memo[2*i]);
            
            if(2*i+1<=n) {
                memo[2*i+1] = memo[i] + memo[i+1];
                // cout<<2*i<<" "<<2*i+1<<endl;
                
            } 
            if(2*i+1<=n) mx = max(mx, memo[2*i+1]);
        }
        
        return mx;
        
    }
};
