class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {

        sort(tokens.begin(), tokens.end());
        int i = 0, j = tokens.size()-1;
        int coin = 0;
        int res = 0;

        while(i<=j){
            if(power>=tokens[i]){
                coin+=1;
                power-=tokens[i];
                i++;
            }
            else if(coin>0){
                coin-=1;
                power+=tokens[j];
                j--;
            }
            else break;
            res = max(res, coin);
        }
        return res;
    }
};
