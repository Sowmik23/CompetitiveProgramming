// 69. Sqrt(x)
class Solution {
public:
    int mySqrt(int x) {
        
        //using binary search
        /*
        long low = 0, high = x;
        
        while(low<=high){
            long mid = low+(high-low)/2;
            if(mid*mid==x) return mid;
            if(mid*mid>x) high = mid-1;
            else low = mid+1;
        }

        return high;
        */

        //without using long
        /*
        if (x == 0) return 0;
        int start = 1, end = x;
        while (start < end) { 
            int mid = start + (end - start) / 2;
            if (mid <= x / mid && (mid + 1) > x / (mid + 1))// Found the result
                return mid; 
            else if (mid > x / mid)// Keep checking the left part
                end = mid;
            else
                start = mid + 1;// Keep checking the right part
        }
        return start;
        */

        //Newton's Iterative Method
        if(x==0) return 0;
        long a = x;
        while(a>(x/a)){
            a = (a+x/a)/2;
        }
        return a;
    }
};