class Solution {
public:
    int countPrimes(int n) {
        
        if(n<1) return 0;
        return prime(n); // determine prime from 2 to n
    }
    
    
    private:
    int prime(int n){
        vector<int> mark(n+1, true);
        mark[0] = mark[1] = false;
        for(int i=4;i<n;i+=2) mark[i] = false;
        for(int i=3;i*i<n;i++){
            if(mark[i]){
                for(int j=i*i;j<n;j+=(2*i)){
                    mark[j] = false;
                }
            }
        }
        
        int cnt=0;
        for(int i=0;i<n;i++) {
            if(mark[i]) cnt++;
        }
        return cnt;
    }

};
