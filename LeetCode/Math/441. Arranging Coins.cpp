class Solution {
public:
    int arrangeCoins(int n) {
      
        if(n==1) return 1;
        
        int left = 1, right = (n/3)+3;
        while(left<right){
            long long mid = left+(right-left)/2;
            
            long long x = (mid*(mid+1))/2;
            if(x>n){
                right = mid;
            }
            else {
                left = mid+1;
            }
        }
       
         // 1804289383
  
       // cout<<(left*(left+1)/2)<<endl;
      //cout<<left<<endl;
        
        
        return left-1;
    }
};
