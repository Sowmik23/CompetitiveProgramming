class Solution {
public:
    
    //Time: sqrt(c)*logc
    bool judgeSquareSum(int c) {
        
        
        for(long i=0;i*i<=c;i++){
            int j = c-(i*i);
            
            if(binarySearch(0, j, j)==true){
                return true;
            }
        }
        return false;
    }
    
private:
    bool binarySearch(long start, long end, int target){
        if(end>target) return false;
        
        while(start<=end){
            long mid = (start+end)/2;
            if(mid*mid==target) return true;
            else if(mid*mid<target) start = mid+1;
            else if(mid*mid>target) end = mid-1;
        }
        
        return false;
    }
};
