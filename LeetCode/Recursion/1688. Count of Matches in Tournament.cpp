// 1688. Count of Matches in Tournament


class Solution {
public:
    int cnt = 0;
    int numberOfMatches(int n) {
        if(n>1) {
            if(n%2==1) {
                // cnt+=(n/2)+1;
                return numberOfMatches(n/2)+(n/2)+1;
            }
            else {
                // cnt+=(n/2);
                return numberOfMatches(n/2)+(n/2);
            }
        }
        return 0;//cnt;
    }
};