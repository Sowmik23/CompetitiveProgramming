// 1326. Minimum Number of Taps to Open to Water a Garden
class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        
        //Greedy
        //Time: O(n)
        
        return calculate(n, ranges);
    }
private:
    int calculate(int n, vector<int> &ranges){

        int cnt = 0;
        // Create a vector to track the maximum reach for each position
        vector<int> maxReach(n + 1);

        // Calculate the maximum reach for each tap
        for (int i = 0; i < ranges.size(); i++) {

            // Calculate the leftmost position the tap can reach
            int start = max(0, i - ranges[i]);
            
            // Calculate the rightmost position the tap can reach
            int end = min(n, i + ranges[i]);

            // Update the maximum reach for the leftmost position
            maxReach[start] = max(maxReach[start], end);
        }
        
        //now greedy: like if reachable from start to end by finding mx ladder
        int currEnd = 0;
        int nextEnd = 0;
        for(int i=0;i<=n;i++){
            if(i>nextEnd) return -1;
            if(i>currEnd) {
                cnt++;
                currEnd = nextEnd;
            }
            nextEnd = max(nextEnd, maxReach[i]);
        }
        return cnt;
    }
};