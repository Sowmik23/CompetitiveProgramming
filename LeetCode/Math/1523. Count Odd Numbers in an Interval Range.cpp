// 1523. Count Odd Numbers in an Interval Range
class Solution {
public:
    int countOdds(int low, int high) {
        
        //Time: O(1)
        //Space: O(1)
        
        if(high==low) return high&1;
        int x = (high-low+1)/2;
        if(high&1 and low&1) x++;
        return x;
    }
};