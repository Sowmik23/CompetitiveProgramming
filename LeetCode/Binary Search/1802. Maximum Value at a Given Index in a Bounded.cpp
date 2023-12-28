// 1802. Maximum Value at a Given Index in a Bounded Array
class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        
        int low = 1, high = maxSum;

        while(low<high){
            int mid = (low+high+1)/2;
            if(isPossible(mid, index, n)<=maxSum){
                low = mid;
            }
            else high = mid-1;
        }

        return low;
    }
private:
    long isPossible(int mid, int index, int n){
        // long left = 0, right = 0;
        // int val = mid;
        // for(int i=index;i>=0;i--){
        //     left+=val;
        //     val--;
        // }
        // mid--;
        // for(int i=index+1;i<n;i++){
        //     right+=mid;
        //     mid--;
        // }
        // return left+right;

        long count = 0;
        long value = mid;
        // On index's left:
        // If value > index, there are index + 1 numbers in the arithmetic sequence:
        // [value - index, ..., value - 1, value].
        // Otherwise, there are value numbers in the arithmetic sequence:
        // [1, 2, ..., value - 1, value], plus a sequence of length (index - value + 1) of 1s. 
        if (value > index) {
            count += (long)(value + value - index) * (index + 1) / 2;
        } else {
            count += (long)(value + 1) * value / 2 + index - value + 1;
        };

        // On index's right:
        // If value >= n - index, there are n - index numbers in the arithmetic sequence:
        // [value, value - 1, ..., value - n + 1 + index].
        // Otherwise, there are value numbers in the arithmetic sequence:
        // [value, value - 1, ..., 1], plus a sequence of length (n - index - value) of 1s. 
        if (value >= n - index) {
            count += (long)(value + value - n + 1 + index) * (n - index) / 2;
        } else {
            count += (long)(value + 1) * value / 2 + n - index - value;
        }   
        
        return count - value;
    }
};

// 4 5 6 7
// 0 1 2 3