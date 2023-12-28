// 1503. Last Moment Before All Ants Fall Out of a Plank

class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        
        // the collisions are completely irrelevant. :v
        int res = 0;

        for(auto& leftAunt: left){
            res = max(res, leftAunt);
        }

        for(auto& rightAunt: right){
            res = max(res, n-rightAunt);
        }

        return res;
    }
};

// 1 2 3 -> <- 4 5
// <-1 2-> 3-> <- 4 5->
// 2 3 -> <- 4
// <- 2 3-> 4-> 