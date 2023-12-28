// 1561. Maximum Number of Coins You Can Get

class Solution {
public:
    int maxCoins(vector<int>& piles) {
        
        int n = piles.size();
        sort(piles.begin(), piles.end());

        int i = 0;
        int j = n-1;
        int sum = 0;
        while(i<j){
            sum+=piles[j-1];
            i++;
            j-=2;
        }
        return sum;
    }
};



// 1 2 2 4 7 8