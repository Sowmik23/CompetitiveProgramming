// 1406. Stone Game III
class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        
        int n = stoneValue.size();
        vector<int> memo(n+1, INT_MAX);

        int point = recursionWithMemo(stoneValue, memo, 0);
        if(point>0) return "Alice";
        else if(point<0) return "Bob";
        return "Tie";
    }
private:
    int recursionWithMemo(vector<int> &stoneValue, vector<int> &memo, int index){

        if(index>=stoneValue.size()) return 0;
        if(memo[index]!=INT_MAX) return memo[index];

        memo[index] = stoneValue[index] - recursionWithMemo(stoneValue, memo, index+1);
        if(index+2<=stoneValue.size()){
            memo[index] = max(memo[index], stoneValue[index] + stoneValue[index+1] - recursionWithMemo(stoneValue, memo, index+2));
        }
        if(index+3<=stoneValue.size()){
            memo[index] = max(memo[index], stoneValue[index]+stoneValue[index+1]+stoneValue[index+2]-recursionWithMemo(stoneValue, memo, index+3));
        }
        return memo[index];
    }
};