class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        
        set<int> res;
        
        for(int i=1;i<=bound;i*=x){
            for(int j=1;j<=bound;j*=y){
                int sum = i+j;
                if(sum<=bound){
                    res.insert(sum);
                } 
                if(y==1) break;
            }        
            if(x==1) break;
        }
        return vector<int> (res.begin(), res.end());
    }
    
    private:
    long Pow(int x, int n){
        long ans = 1;
        while(n>0){
            if(n&1) ans = ans*x;
            x = x*x;
            n>>=1;
        }
        return ans;
    }
};
